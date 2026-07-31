const path = require('node:path');
const fs = require('node:fs/promises');

const webConfig = require('./web-config.json');
const helper = require('../helper.js')
const logger = require('../logger.js');
const timer = require('../timer.js')
const queries = require('./queries.js')

// reads JSON data from the mentioned path; 
// creates a JSON file with default-value if file not found
async function readFromJSON(filePath, defaultValue = []) {
	try {
		await fs.mkdir(path.dirname(filePath), { recursive: true });
		const problemsJSON = await fs.readFile(filePath, { encoding: "utf8" })

		return JSON.parse(problemsJSON)
	} catch (err) {
		if (err.code === 'ENOENT') {
			// logger.info(`JSON file not found. Creating new file at: ${filePath}`);
			await fs.writeFile(filePath, JSON.stringify(defaultValue, null, 4));

			return defaultValue;
		}
		throw err
	}
}

// writes JSON data into the file at path
async function writeToJSON(filePath, data) {
	try {
		await fs.mkdir(path.dirname(filePath), { recursive: true });
		await fs.writeFile(filePath, JSON.stringify(data, null, 4));
	} catch (err) {
		throw err
	}
}

// moves the source file (if exists) to a timestamped backup
async function createBackupJSON(sourceFilePath) {
	// ensure source file exists, create if missing
	try {
		await fs.access(sourceFilePath);
	} catch (err) {
		if (err.code === "ENOENT") {
			logger.info("Source file does not exist. No backup created");
			return null
		}
		throw err;
	}

	try {
		await helper.ensureDir('webBackup')
		const backupDirPath = helper.getDirPath('webBackup')

		const ext = path.extname(sourceFilePath); // file-extension
		const sourceFileName = path.basename(sourceFilePath, ext); // filename without extension
		const timestamp = timer.getFileSafeISOTimestamp();
		const backupFileName = `${sourceFileName} [${timestamp}]${ext}`; // timestamped backup filename
		const backupFilePath = path.join(backupDirPath, backupFileName)

		// create the backup file and delete the source file
		await fs.copyFile(sourceFilePath, backupFilePath);

		logger.info(`Backup created: ${helper.getRootRelativePath(backupFilePath)}`)
	} catch (err) {
		throw err
	}
}

async function updateConfig() {
	try {
		const filePathConfig = path.join(__dirname, 'web-config.json');
		await writeToJSON(filePathConfig, webConfig)
	} catch (err) {
		throw err;
	}
}

// process file writes in small batches instead of concurrently prcoessing in bulk
async function batchWrite(problems, version) {
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
}

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

			return await readFromJSON(filePathJSON)
		}

		const query = queries.LC_Base_Problem_List;

		logger.info('Fetching new problem list from Leetcode API...')

		// start the loading text while waiting for API response
		const apiFetchStartTime = Date.now();
		const apiInProgressInterval = setInterval(() => {
			const elapsed = Math.floor((Date.now() - apiFetchStartTime) / 1000);
			console.log(`Waiting for LeetCode Full Problem list API response... (${elapsed}s elapsed)`);
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

		const problems = data.allQuestions

		problems.sort((a, b) => Number(a.questionFrontendId) - Number(b.questionFrontendId));

		// create a backup of the old json
		await createBackupJSON(filePathJSON)
		// create the json with fresh data
		await writeToJSON(filePathJSON, problems)

		webConfig.LAST_UPDATED_ISO = new Date().toISOString()
		await updateConfig()

		return problems
	} catch (err) {
		throw err;
	}
}

function parseProblem(problem) {
	try {
		const parseJSON = (value, fallback) => {
			try {
				return typeof value === "string" ? JSON.parse(value) : value;
			} catch {
				return fallback;
			}
		};

		return {
			quesId: Number(problem.questionFrontendId),
			quesIdLCBackend: Number(problem.questionId),
			title: problem.title,
			titleSlug: problem.titleSlug,
			difficulty: problem.difficulty,
			likes: problem.likes,
			dislikes: problem.dislikes,
			acRate: problem.acRate,
			isPaidOnly: problem.isPaidOnly,
			categoryTitle: problem.categoryTitle,
			hasSolution: problem.hasSolution,
			hasVideoSolution: problem.hasVideoSolution,
			stats: JSON.parse(problem.stats),
			similarQuestions: parseJSON(problem.similarQuestions, []),
			solution: {
				canSeeDetail: problem.solution?.canSeeDetail ?? false
			},
			topicTags: problem.topicTags ?? [],
			companyTagStats: problem.companyTagStats,
		};
	} catch (err) {
		logger.info(err)
		throw err;
	}
}

// fetch details for a specific problem by its title-slug,
// parse in a custom format
async function fetchProblem(titleSlug) {
	try {
		const query = queries.LC_Problem_Detail

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

		const problem = parseProblem(data.question);

		const filenameJSON = `${problem.quesId}.${problem.titleSlug}.json`
		const filePathJSON = path.join(helper.getDirPath('LCProblemsJSON'), filenameJSON)
		await writeToJSON(filePathJSON, data.question)

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
		} else {
			problems = await readFromJSON(filePath)
		}

		if (baseProblems.length === problems.length) {
			return detailedProblems
		}
		else if (baseProblems.length < problems.length) {
			throw new Error('Problems length mismatch')
		}

		for (let i = problems.length, limit = webConfig.FETCH_NEXT_COUNT ?? 5;
			i < baseProblems.length && limit > 0;
			i++, limit--) {
			const { questionFrontendId, title, titleSlug } = baseProblems[i]
			logger.info(`Fetching... ${questionFrontendId}.${title}`)

			const problem = await fetchProblem(titleSlug)
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
		logger.error(err);
		throw err;
	}
}

function initDirs() {
	try {
		helper.ensureDir('LCProblemsJSON')
	} catch (err) {
		throw err
	}
}

async function fetchStatsFromLC() {
	try {
		const startTime = Date.now();
		const scriptName = path.basename(__filename)
		logger.info('')
		logger.time(`${scriptName} started...`)

		initDirs()

		const baseProblems = await fetchBaseProblemList();
		logger.info('Problem list length = ' + baseProblems.length)
		logger.info('Problem at index 0 = ' + JSON.stringify(baseProblems[0]))

		const problems = await fetchProblems(baseProblems)
		logger.info('Detailed Problem list length = ' + problems.length)

		if (logger.hasError()) {
			console.log('Issue(s) found during execution: check logs')
		}

		const endTime = Date.now();
		logger.time(`${scriptName} completed.`)
		logger.time(`Time Taken to run ${scriptName} = ${endTime - startTime} ms`);

	} catch (err) {
		console.error(err)
		logger.error(err)
	}
}

fetchStatsFromLC()
