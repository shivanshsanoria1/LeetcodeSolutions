const path = require('node:path');

const webConfig = require('./web-config.json');
const helper = require('../helper.js')
const logger = require('../logger.js');
const timer = require('../timer.js')
const queries = require('./queries.js')

// provide delay in ms
const sleep = (time_ms = webConfig.API_DELAY_MS ?? 250) => new Promise((resolve) => setTimeout(resolve, time_ms));

// fetch a list of all problems from LC-API, moves old data to backup;
// use the local version if last fetch was less than 7 days ago;
// use manual override to force refresh the list
async function fetchBaseProblemList() {
	try {
		const filePathJSON = helper.getFilePath('LCBaseProblemList')
		const lastUpdatedTimestamp = (() => {
			const date = new Date(webConfig?.LAST_UPDATED_ISO ?? 0);
			return Number.isNaN(date.getTime()) ? new Date(0) : date;
		})();

		logger.info('LC Base List last updated at: ' + lastUpdatedTimestamp)

		// last update was less than 7 days ago; don't fetch new data from API
		if (!webConfig.FORCE_REFRESH_BASE_PROBLEM_LIST &&
			Date.now() - lastUpdatedTimestamp.getTime() < 7 * 24 * 60 * 60 * 1000) {
			logger.info('Using the local version of LC-problem-list')

			const baseProblemsLocal = await readFromJSON(filePathJSON)
			if (baseProblemsLocal.length > 0) {
				return baseProblemsLocal
			}
		}

		const query = queries.LC_Base_Problem_List;

		logger.info('Fetching new problem list from Leetcode API...')

		// start the loading text while waiting for API response
		const apiFetchStartTime = Date.now();
		const apiInProgressInterval = setInterval(() => {
			const elapsed = Math.floor((Date.now() - apiFetchStartTime) / 1000);
			logger.info(`Waiting for LeetCode Full Problem list API response... (${elapsed}s elapsed)`);
		}, 3000);

		const res = await fetch(webConfig.API_URL, {
			method: "POST",
			headers: {
				"Content-Type": "application/json",
				"Origin": webConfig.ORIGIN,
				"Referer": webConfig.REFERER,
				"User-Agent": "Mozilla/5.0"
			},
			body: JSON.stringify({ query })
		});
		// stop the loading text
		clearInterval(apiInProgressInterval);

		if (!res.ok) {
			const text = await res.text();
			logger.info("Response body:", text);
			throw new Error(`HTTP ${res.status}`);
		}

		const { data, errors } = await res.json();

		if (errors) {
			logger.error(errors);
			throw new Error("GraphQL error");
		}

		if (!data || !data.allQuestions) {
			throw new Error("Problem list not found");
		}

		const baseProblems = data.allQuestions

		baseProblems.sort((a, b) => Number(a.questionFrontendId) - Number(b.questionFrontendId));

		// create a backup of the old json
		await createBackupJSON(filePathJSON)
		// create the json with fresh data
		await writeToJSON(filePathJSON, baseProblems)

		webConfig.LAST_UPDATED_ISO = new Date().toISOString()
		await updateConfig()

		return baseProblems
	} catch (err) {
		throw err;
	}
}

function findQuesIdFromSlug(baseProblems, titleSlug) {
	try {
		for (const baseProblem of baseProblems) {
			if (baseProblem.titleSlug === titleSlug) {
				return Number(baseProblem.questionFrontendId)
			}
		}

		return -1
	} catch (err) {
		throw err
	}
}

// parse the problem stats in a custom format
function parseProblem(problem, baseProblems) {
	try {
		const parseJSONString = (value, fallback = []) => {
			try {
				return typeof value === "string" ? JSON.parse(value) : value;
			} catch {
				return fallback;
			}
		};

		const parsedProblemObj = {
			quesId: Number(problem.questionFrontendId),
			title: problem.title,
			titleSlug: problem.titleSlug,
			difficulty: problem.difficulty,
			isPaidOnly: problem.isPaidOnly,
			categoryTitle: problem.categoryTitle,
			stats: JSON.parse(problem.stats),
			similarQuestions: parseJSONString(problem.similarQuestions).map(q => q.titleSlug),
			similarQuesIds: parseJSONString(problem.similarQuestions)
				.map(({ titleSlug }) => findQuesIdFromSlug(baseProblems, titleSlug)),
			topicTags: problem.topicTags ?? [],
			meta: {
				quesIdLCBackend: Number(problem.questionId),
				hasSolution: problem.hasSolution,
				hasVideoSolution: problem.hasVideoSolution,
			},
			solution: {
				canSeeDetail: problem.solution?.canSeeDetail ?? false,
			}
		};

		parsedProblemObj.stats.acRateRaw = problem.acRate
		parsedProblemObj.stats.likes = problem.likes
		parsedProblemObj.stats.dislikes = problem.dislikes

		return parsedProblemObj
	} catch (err) {
		logger.info(err)
		throw err;
	}
}

// parse the full problem stats in a custom format to store into a JSON file
function parseProblemJSON(problem, baseProblems) {
	try {
		const parsedProblemObj = parseProblem(problem, baseProblems)

		parsedProblemObj.solution.content = problem.solution?.content
		parsedProblemObj.content = problem.content
		parsedProblemObj.hints = problem.hints
		parsedProblemObj.codeSnippets = problem.codeSnippets

		return parsedProblemObj
	} catch (err) {
		logger.info(err)
		throw err;
	}
}

// verifies each problem in problems[] has its JSON file
async function verifyProblemJSON(problems) {
	try {
		const dirPathJSON = helper.getDirPath('LCProblemsJSON')
		const files = await readFromJSON(dirPathJSON);

		if (files.length !== problems.length) {
			logger.error('JSON files mismatch found.')
		}

		const fileMap = {};
		for (const file of files) {
			if (!file.endsWith('.json')) {
				throw new Error(`Invalid filename = ${file}`)
			}

			const quesId = Number(file.split('.')[0])
			const titleSlug = file.split('.')[1]

			fileMap[quesId] = titleSlug;
		}

		for (const { quesId, titleSlug } of problems) {
			if (!fileMap[quesId]) {
				throw new Error(`quesId = ${quesId} JSON file not found.`)
			} else if (fileMap[quesId] !== titleSlug) {
				throw new Error(`quesId = ${quesId} title slug mismatch. Title slug = ${titleSlug}, filename = ${fileMap[quesId]}`)
			}
		}
	} catch (err) {
		throw err
	}
}

// fetch details for a specific problem by its title-slug,
// parse in a custom format
async function fetchProblem(titleSlug, baseProblems) {
	try {
		const query = queries.LC_Problem_Detailed

		const res = await fetch(webConfig.API_URL, {
			method: "POST",
			headers: {
				"Content-Type": "application/json",
				"Origin": webConfig.ORIGIN,
				"Referer": webConfig.REFERER,
				"User-Agent": "Mozilla/5.0"
			},
			body: JSON.stringify({
				query,
				variables: { titleSlug }
			})
		});

		if (!res.ok) {
			const text = await res.text();
			throw new Error(`HTTP ${res.status}: ${text}`);
		}

		const { data, errors } = await res.json();

		if (errors) {
			logger.error(errors);
			throw new Error("GraphQL error");
		}

		if (!data || !data.question) {
			throw new Error("Problem not found");
		}

		const problem = parseProblem(data.question, baseProblems);

		const filenameJSON = `${problem.quesId}.${problem.titleSlug}.json`
		const filePathJSON = path.join(helper.getDirPath('LCProblemsJSON'), filenameJSON)
		await writeToJSON(filePathJSON, parseProblemJSON(data.question, baseProblems))

		return problem

	} catch (err) {
		logger.info(err);
		throw err;
	}
}

// uses the base problem list to fetch the details for each missing problem sequentially (with limiter);
// append the new items to the old data list;
// use manual override to force refresh the list (use with CAUTION, full refresh too slow)
// takes backup before full refresh
async function fetchProblems(baseProblems) {
	try {
		const filePath = helper.getFilePath('LCProblemList')
		let problems = []

		if (webConfig.FORCE_REFRESH_PROBLEM_LIST) {
			// create a backup of the old json
			await createBackupJSON(filePath)

			await createBackupDir(helper.getDirPath('LCProblemsJSON'))
		} else {
			problems = await readFromJSON(filePath)
		}
		logger.info(`Base Problems length = ${baseProblems.length}`)
		logger.info(`Problems length = ${problems.length}`)

		if (baseProblems.length === problems.length) {
			return problems
		}
		else if (baseProblems.length < problems.length) {
			throw new Error('Problems length mismatch')
		}

		await verifyProblemJSON(problems)

		for (let i = problems.length, limit = webConfig.FETCH_NEXT_COUNT ?? 5;
			i < baseProblems.length && limit > 0;
			i++, limit--) {
			const { questionFrontendId, title, titleSlug } = baseProblems[i]
			logger.info(`Fetching... ${questionFrontendId}.${title}`)

			const problem = await fetchProblem(titleSlug, baseProblems)
			problems.push(problem)

			await sleep() // prevent overwhelming the API
		}

		await writeToJSON(filePath, problems)

		// switch OFF the FORCE REFRESH flag
		if (webConfig.FORCE_REFRESH_PROBLEM_LIST) {
			webConfig.FORCE_REFRESH_PROBLEM_LIST = false
			await updateConfig()
			logger.info('FORCE_REFRESH_PROBLEM_LIST_DETAILED flag reset to: false')
		}

		return problems
	} catch (err) {
		throw err;
	}
}

async function generateTopicTagMap(problems) {
	try {
		const topicTagMap = {}
		for (const { topicTags } of problems) {
			for (const { name, slug } of topicTags) {
				topicTagMap[slug] = name
			}
		}

		const filePath = helper.getFilePath('LCTopicTag')
		await writeToJSON(filePath, topicTagMap)

		return topicTagMap
	} catch (err) {
		throw err
	}
}

async function fetchStatsFromLC() {
	try {
		const startTime = Date.now();
		const scriptName = path.basename(__filename)
		logger.info('')
		logger.time(`${scriptName} running...`)

		const baseProblems = await fetchBaseProblemList();
		logger.info('Base Problem list length = ' + baseProblems.length)
		logger.info('Base Problem at index 0 = ' + JSON.stringify(baseProblems[0]))

		const problems = await fetchProblems(baseProblems)
		logger.info('Main Problem list length = ' + problems.length)
		logger.info('Main Problem at index 0 = ' + JSON.stringify(problems[0]))

		if (logger.getErrorCount() > 0) {
			console.log('Issue(s) found during execution: check logs')
		}

		const topicTagMap = await generateTopicTagMap(problems)
		logger.info('Topic tag map size = ' + Object.keys(topicTagMap).length)

		const endTime = Date.now();
		logger.time(`${scriptName} completed.`)
		logger.time(`Time Taken to run ${scriptName} = ${endTime - startTime} ms`);

	} catch (err) {
		console.error(err)
		logger.error(err)
	}
}

fetchStatsFromLC()

// DEPRICIATED
// process file writes in small batches instead of concurrently prcoessing in bulk
/*async function batchWrite(problems, version) {
	try {
		const batchSize = webConfig.BATCH_SIZE ?? 10
		for (let i = 0; i < problems.length; i += batchSize) {
			const batch = []
			for (let j = i; j < Math.min(problems.length, i + batchSize); j++) {
				const { id, slug } = problems[j]

				if (version === 'html') {
					const { description } = problems[j]
					batch.push(writeToHTML(id, slug, description))
				} else if (version === 'md') {
					const { solutionContent } = problems[j]
					batch.push(writeToMD(id, slug, solutionContent))
				} else {
					throw new Error('Invalid batch write version ' + version)
				}
			}

			await Promise.all(batch)
		}
	} catch (err) {
		logger.info(err)
		throw err
	}
}*/

/*function initDirs() {
	try {
		helper.ensureDir('LCProblemsJSON')
	} catch (err) {
		throw err
	}
}*/

