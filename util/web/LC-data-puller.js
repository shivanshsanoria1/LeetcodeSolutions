const path = require('node:path');
const fs = require('node:fs/promises')

const config = require('../config.json')
const webConfig = require('./web-config.json');
const helper = require('../helper.js')
const timer = require('../timer.js')
const logger = require('../logger.js');
const queries = require('./queries.js')

const API_DELAY_MS = webConfig.API_DELAY_MS ?? 250 // Default: 250ms 
const FORCE_REFRESH_BASE_PROBLEM_LIST = webConfig.FORCE_REFRESH_BASE_PROBLEM_LIST ?? false
const FORCE_REFRESH_PROBLEM_LIST = webConfig.FORCE_REFRESH_PROBLEM_LIST ?? false
const FETCH_NEXT_COUNT = webConfig.FETCH_NEXT_COUNT ?? 5
const API_TIMEOUT_MS = webConfig.API_TIMEOUT_MS ?? 10000 // Default: 10 sec 

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
		if (!FORCE_REFRESH_BASE_PROBLEM_LIST &&
			Date.now() - lastUpdatedTimestamp.getTime() < 7 * 24 * 60 * 60 * 1000) {
			logger.info('Using the local version of Base LC-problem-list')

			const baseProblemsLocal = await readFromJSON(filePathJSON)
			if (baseProblemsLocal.length > 0) {
				return baseProblemsLocal
			}
		}

		logger.info('Fetching new problem list from Leetcode API...')

		// start the loading text while waiting for API response
		const apiFetchStartTime = Date.now();
		const apiInProgressInterval = setInterval(() => {
			const elapsed = Math.floor((Date.now() - apiFetchStartTime) / 1000);
			logger.info(`Waiting for LeetCode Base Problem list API response... (${elapsed}s elapsed)`);
		}, 3000);

		const res = await fetch(webConfig.API_URL, {
			method: "POST",
			headers: {
				"Content-Type": "application/json",
				"Origin": webConfig.ORIGIN,
				"Referer": webConfig.REFERER,
				"User-Agent": "Mozilla/5.0"
			},
			body: JSON.stringify({ query: queries.LC_Base_Problem_List })
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

		//switch OFF the FORCE REFRESH flag
		if (webConfig.FORCE_REFRESH_BASE_PROBLEM_LIST) {
			webConfig.FORCE_REFRESH_BASE_PROBLEM_LIST = false
			await updateConfig('web')
			logger.info('FORCE_REFRESH_BASE_PROBLEM_LIST flag Reset to: false')
		} else {
			await updateConfig('web')
		}

		config.MAX_QUES_ID = Number(baseProblems[baseProblems.length - 1].questionFrontendId)
		await updateConfig('local')
		logger.info('Updated the MAX_QUES_ID in config.json to ' + config.MAX_QUES_ID)

		return baseProblems
	} catch (err) {
		throw err;
	}
}

async function createRawJSONFilenameMap() {
	try {
		const dirPath = helper.getDirPath('LCProblemsJSONRaw')
		const filenames = await fs.readdir(dirPath);

		const rawJSONFilenameMap = new Map();

		for (const filename of filenames) {
			if (!filename.endsWith(".json")) {
				logger.info(`Invalid filename in JSON Raw dir: ${filename}`)
				continue;
			}

			const quesId = Number(filename.split('.')[0])
			const titleSlug = filename.split('.')[1]

			rawJSONFilenameMap.set(quesId, titleSlug)
		}

		return rawJSONFilenameMap
	} catch (err) {
		throw err
	}
}

async function fetchRawProblems(baseProblems, rawJSONFilenameMap) {
	// provide delay in ms
	const sleep = (time_ms = API_DELAY_MS) => new Promise((resolve) => setTimeout(resolve, time_ms));

	try {
		let limit = FETCH_NEXT_COUNT;
		for (let i = 0; i < baseProblems.length && limit > 0; i++) {
			const { questionFrontendId, title, titleSlug } = baseProblems[i]

			if (rawJSONFilenameMap.get(Number(questionFrontendId))) {
				// logger.info(`${questionFrontendId} already has its Raw JSON`)
				continue;
			}

			logger.info(`Fetching... ${questionFrontendId}.${title}`)
			const fetchAPISuccess = await fetchProblem(titleSlug)

			if (fetchAPISuccess === false) {//fetch API failed
				logger.error('Fetch API Failure. Stopping script...')
				break;
			}

			limit--
			await sleep() // prevent overwhelming the API
		}
	} catch (err) {
		throw err;
	}
}

function parseRawProblem(baseProblems, problemRaw) {
	try {
		const parseJSONString = (value, fallback = []) => {
			try {
				return typeof value === "string" ? JSON.parse(value) : value;
			} catch {
				return fallback;
			}
		};

		const findQuesIdFromSlug = (baseProblems, titleSlug) => Number(baseProblems.find(p => p.titleSlug === titleSlug)?.questionFrontendId ?? -1);

		const parsedProblemObj = {
			quesId: Number(problemRaw.questionFrontendId),
			title: problemRaw.title,
			titleSlug: problemRaw.titleSlug,
			difficulty: problemRaw.difficulty,
			isPaidOnly: problemRaw.isPaidOnly,
			categoryTitle: problemRaw.categoryTitle,
			stats: JSON.parse(problemRaw.stats),
			// similarQuestions: parseJSONString(problemRaw.similarQuestions).map(q => q.titleSlug),
			similarQuesIds: parseJSONString(problemRaw.similarQuestions)
				.map(({ titleSlug }) => findQuesIdFromSlug(baseProblems, titleSlug)),
			topicTags: problemRaw.topicTags ?? [],
			meta: {
				quesIdLCBackend: Number(problemRaw.questionId),
				hasSolution: problemRaw.hasSolution,
				hasVideoSolution: problemRaw.hasVideoSolution,
			},
			solution: {
				canSeeDetail: problemRaw.solution?.canSeeDetail ?? false,
			}
		};

		parsedProblemObj.stats.acRateRaw = problemRaw.acRate
		parsedProblemObj.stats.likes = problemRaw.likes
		parsedProblemObj.stats.dislikes = problemRaw.dislikes

		parsedProblemObj.solution.content = problemRaw.solution?.content
		parsedProblemObj.content = problemRaw.content
		parsedProblemObj.hints = problemRaw.hints

		parsedProblemObj.LAST_UPDATED_ISO = timer.getTimestamp('ISO')

		return parsedProblemObj
	} catch (err) {
		throw err;
	}
}

async function parseRawProblems(baseProblems, rawJSONFilenameMap) {
	try {
		const problems = []
		for (const [quesId, titleSlug] of rawJSONFilenameMap) {
			const filenameJSON = `${quesId}.${titleSlug}.json`
			const filePathJSONRaw = path.join(helper.getDirPath('LCProblemsJSONRaw'), filenameJSON)

			const problemRaw = await readFromJSON(filePathJSONRaw)

			const problem = parseRawProblem(baseProblems, problemRaw)

			const filePathJSON = path.join(helper.getDirPath('LCProblemsJSON'), filenameJSON)
			await writeToJSON(filePathJSON, problem)

			problems.push(problem)
		}

		problems.sort((a, b) => Number(a.quesId) - Number(b.quesId));

		const filePathJSON = helper.getFilePath('LCProblemList')
		await writeToJSON(filePathJSON, problems)

		const filePathJSONMin = helper.getFilePath('LCProblemListMin')
		await writeToJSON(filePathJSONMin, problems, true)

		return problems
	} catch (err) {
		throw err;
	}
}

// fetch details for a specific problem by its title-slug
// return API success/failure status
async function fetchProblem(titleSlug) {
	let fetchAPISuccess = false

	const controller = new AbortController()
	const timeout = setTimeout(() => {
		controller.abort()
	}, API_TIMEOUT_MS)

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
			}),
			signal: controller.signal
		});

		fetchAPISuccess = true

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

		const problem = data.question

		//const problem = parseProblem(data.question, baseProblems);

		problem.LAST_UPDATED_ISO = timer.getTimestamp('ISO')

		const filenameJSON = `${problem.questionFrontendId}.${problem.titleSlug}.json`

		const filePathJSONRaw = path.join(helper.getDirPath('LCProblemsJSONRaw'), filenameJSON)
		await writeToJSON(filePathJSONRaw, problem)

		// const filePathJSON = path.join(helper.getDirPath('LCProblemsJSON'), filenameJSON)
		// await writeToJSON(filePathJSON, parseProblemJSON(data.question, baseProblems))

		// return problem

		return fetchAPISuccess
	} catch (err) {
		if (err.name === "AbortError") {
			logger.error(`API timeout: LeetCode API did not respond within ${API_TIMEOUT_MS} ms for "${titleSlug}"`)
		}

		logger.info(err);
		if (fetchAPISuccess === false) {
			return fetchAPISuccess
		}
		throw err;
	} finally {
		clearTimeout(timeout)
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

		// no need to take backup of topic tags
		// await createBackupJSON(filePath)
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
		logger.time('Open the logs file to see contiuous updates.')

		const baseProblems = await fetchBaseProblemList();
		logger.info('Base Problem list length = ' + baseProblems.length)
		logger.info('Base Problem at index 0 = ' + JSON.stringify(baseProblems[0]))

		let rawJSONFilenameMap = await createRawJSONFilenameMap()
		logger.info(`raw JSON file map first pair = 1: ${rawJSONFilenameMap.get(1)}`)

		await fetchRawProblems(baseProblems, rawJSONFilenameMap)

		rawJSONFilenameMap = await createRawJSONFilenameMap()
		logger.info(`raw JSON file map first pair = 1: ${rawJSONFilenameMap.get(1)}`)

		const problems = await parseRawProblems(baseProblems, rawJSONFilenameMap)
		logger.info('Main Problem list length = ' + problems.length)
		logger.info('Main Problem at index 0 = ' + JSON.stringify(problems[0]))

		const topicTagMap = await generateTopicTagMap(problems)
		logger.info('Topic tag map size = ' + Object.keys(topicTagMap).length)

		if (logger.getErrorCount() > 0) {
			console.log('Issue(s) found during execution: check logs')
		}

		const endTime = Date.now();
		logger.time(`${scriptName} completed.`)
		logger.time(`Time Taken to run ${scriptName} = ${((endTime - startTime) / 1000).toFixed(2)} s`);

	} catch (err) {
		console.error(err)
		logger.error(err)
	}
}

fetchStatsFromLC()

// Reads JSON data from a file path.
// Writes defaultValue if the existing file is empty.
async function readFromJSON(filePath, defaultValue = []) {
	try {
		const jsonData = await fs.readFile(filePath, 'utf8');

		if (!jsonData.trim()) {
			await writeToJSON(filePath, defaultValue);
			return defaultValue;
		}

		return JSON.parse(jsonData);
	} catch (err) {
		if (err.code === 'ENOENT') {
			throw new Error(
				`JSON file does not exist: ${filePath}. ` +
				`Use helper.getFilePath() to obtain the file path.`
			);
		}

		throw err;
	}
}

async function writeToJSON(filePath, data = {}, minifiedFlag = false) {
	try {
		if (minifiedFlag) {
			await fs.writeFile(filePath, JSON.stringify(data), 'utf8');
		} else {
			await fs.writeFile(filePath, JSON.stringify(data, null, 4), 'utf8');
		}
	} catch (err) {
		throw err;
	}
}

// Moves the source file to a timestamped backup.
// Does nothing if the source file does not exist.
async function createBackupJSON(sourceFilePath) {
	try {
		await fs.access(sourceFilePath);
	} catch (err) {
		if (err.code === 'ENOENT') {
			logger.info(`Source JSON file does not exist: ${sourceFilePath}`);
			return null;
		}

		throw err;
	}

	try {
		const backupDirPath = helper.getDirPath('webBackup');

		const ext = path.extname(sourceFilePath);
		const sourceFileName = path.basename(sourceFilePath, ext);
		const timestamp = timer.getFileSafeISOTimestamp();

		const backupFileName = `${sourceFileName} [${timestamp}]${ext}`;
		const backupFilePath = path.join(backupDirPath, backupFileName);

		await fs.rename(sourceFilePath, backupFilePath);

		logger.info(`Backup created: ${helper.getRootRelativePath(backupFilePath)}`);

		return backupFilePath;
	} catch (err) {
		throw err;
	}
}

async function createBackupDir(sourceDirPath) {
	try {
		await fs.access(sourceDirPath);
	} catch (err) {
		if (err.code === 'ENOENT') {
			logger.info(`Source directory does not exist: ${sourceDirPath}`);
			return null;
		}

		throw err;
	}

	try {
		const backupDirPath = helper.getDirPath('webBackup');

		const sourceDirName = path.basename(sourceDirPath);
		const timestamp = timer.getFileSafeISOTimestamp();

		const backupDirName = `${sourceDirName} [${timestamp}]`;
		const backupDirFullPath = path.join(backupDirPath, backupDirName);

		await fs.rename(sourceDirPath, backupDirFullPath);

		logger.info(`Backup created: ${helper.getRootRelativePath(backupDirFullPath)}`);

		return backupDirFullPath;
	} catch (err) {
		throw err;
	}
}

async function updateConfig(mode = 'local') {
	try {
		if (mode === 'web') {
			const filePath = helper.getFilePath('webConfig');
			await writeToJSON(filePath, webConfig);
			logger.info('Updated web-config.json')

			return
		}

		const filePath = helper.getFilePath('config')
		await writeToJSON(filePath, config);

		logger.info('Updated config.json')
	} catch (err) {
		throw err;
	}
}

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

