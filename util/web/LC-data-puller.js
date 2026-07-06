const path = require('node:path');
const fs = require('node:fs/promises');

const webConfig = require('./web-config.json');
const helper = require('../helper.js')
const logger = require('../logger.js');
const timer = require('../timer.js')

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

function writeToHTML(id, slug, data) {
	try {
		const filename = `${id}.${slug}.html`
		const filePath = path.join(__dirname, '..', 'generated', 'html', filename)

		// await fs.mkdir(path.dirname(filePath), { recursive: true });
		return fs.writeFile(filePath, data, "utf-8");
	} catch (err) {
		logger.info(err)
		throw err
	}
}

// process file writes in small batches instead of concurrently prcoessing in bulk
async function batchWrite(problems) {
	try {
		for (let i = 0; i < problems.length; i += config.BATCH_SIZE) {
			const batch = []
			for (let j = i; j < Math.min(problems.length, i + config.BATCH_SIZE); j++) {
				const { id, slug, description } = problems[j]
				batch.push(writeToHTML(id, slug, description))
			}

			await Promise.all(batch)
		}
	} catch (err) {
		logger.info(err)
		throw err
	}
}

// fetch a list of all problems from LC-API, moves old data to backup;
// use the local version if last fetch was less than 7 days ago;
// use manual override to force refresh the list
async function fetchAllProblems() {
	try {
		const filePathJSON = helper.getFilePath('LCProblemList')
		const lastUpdatedTimestamp = new Date(webConfig.LAST_UPDATED_ISO)

		// last update was less than 7 days ago; don't fetch new data from API
		if (!webConfig.FORCE_REFRESH_PROBLEM_LIST &&
			lastUpdatedTimestamp.toString() !== "Invalid Date" &&
			Date.now() - lastUpdatedTimestamp.getTime() < 7 * 24 * 60 * 60 * 1000) {
			logger.info('Using the local version of LC-problem-list')

			return await readFromJSON(filePathJSON)
		}

		const query = `
			query allQuestions {
				allQuestions {
					questionFrontendId
					title
					titleSlug
					difficulty
					isPaidOnly
					acRate
					topicTags {
						name
						slug
					}
				}
			}
		`;

		logger.info('Fetching new problem list from Leetcode API...')

		const start = Date.now();

		const interval = setInterval(() => {
			const elapsed = Math.floor((Date.now() - start) / 1000);
			logger.info(`Still waiting for LeetCode API response... (${elapsed}s elapsed)`);
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

		clearInterval(interval);

		if (!res.ok) {
			const text = await res.text();
			logger.info("Response body:", text);
			throw new Error(`HTTP ${res.status}`);
		}

		const { data, errors } = await res.json();

		if (errors) {
			logger.info(errors);
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

		logger.info('Fetched problem list length = ' + problems.length)

		return problems
	} catch (err) {
		throw err;
	}
}

function parseDetailedProblem(problem) {
	try {
		const stats = JSON.parse(problem.stats)

		return {
			id: parseInt(problem.questionFrontendId),
			questionIdInternal: parseInt(problem.questionId),
			title: problem.title,
			slug: problem.titleSlug,
			difficulty: problem.difficulty,
			likes: problem.likes,
			dislikes: problem.dislikes,
			acceptanceRate: Number(problem.acRate.toFixed(2)),
			isPaid: problem.isPaidOnly,
			stats: {
				accepted: stats.totalAcceptedRaw,
				submissions: stats.totalSubmissionRaw,
				acceptedDisplayed: stats.totalAccepted,
				submissionsDisplayed: stats.totalSubmission,
				acceptanceRate: stats.acRate,
			},
			description: problem.content ?? '',
			tags: problem.topicTags.map(tag => tag.name),
		};
	} catch (err) {
		logger.info(err)
		throw err;
	}
}

// fetch details for a specific problem by its title-slug from LC-API,
// parse in a custom format
async function fetchProblemDetailed(titleSlug) {
	try {
		const query = `
			query getQuestionPublicData($titleSlug: String!) {
				question(titleSlug: $titleSlug) {
					questionId
					questionFrontendId
					title
					titleSlug
					difficulty
					likes
					dislikes
					acRate
					isPaidOnly
					categoryTitle
					stats
					content
					topicTags {
						name
						slug
					}
				}
			}
		`;

		const res = await fetch(config.API_URL, {
			method: "POST",
			headers: {
				"Content-Type": "application/json",
				"Origin": config.ORIGIN,
				"Referer": config.REFERER,
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
			logger.info(errors);
			throw new Error("GraphQL error");
		}

		if (!data || !data.question) {
			throw new Error("Problem not found");
		}

		return parseDetailedProblem(data.question);

	} catch (err) {
		logger.info(err);
		throw err;
	}
}

// provide delay in ms
const sleep = (time_ms = config.API_DELAY_MS ?? 250) => new Promise((resolve) => setTimeout(resolve, time_ms));

// uses the base problem list to fetch the details for each missing problem sequentially (with limiter);
// append the new items to the old data list;
// use manual override to force refresh the list (use with CAUTION, full refresh too slow)
// takes backup before full refresh
async function fetchProblemsDetailed(problems) {
	try {
		const filePath = path.join(__dirname, '..', 'generated', config.PROBLEM_LIST_DETAILED_FILE);
		let problemsDetailed = []

		if (config.FORCE_REFRESH_PROBLEM_LIST_DETAILED) {
			// create a backup of the old json
			await createBackupJSON(filePath)
		} else {
			problemsDetailed = await readFromJSON(filePath)
		}

		if (problems.length === problemsDetailed.length) return problemsDetailed
		else if (problems.length < problemsDetailed.length) throw new Error('Problems length mismatch')

		const promisesHTML = []
		for (let i = problemsDetailed.length, limit = config.FETCH_NEXT_COUNT;
			i < problems.length && limit > 0;
			i++, limit--) {
			const { questionFrontendId, title, titleSlug } = problems[i]
			logger.info(`Fetching... ${questionFrontendId}.${title}`)

			const problem = await fetchProblemDetailed(titleSlug)

			const { id, slug, description } = problem
			promisesHTML.push({ id, slug, description })
			delete problem.description

			problemsDetailed.push(problem)

			await sleep(250) // prevent overwhelming the API
		}

		await writeToJSON(filePath, problemsDetailed)

		await batchWrite(promisesHTML)

		if (config.FORCE_REFRESH_PROBLEM_LIST_DETAILED) {
			config.FORCE_REFRESH_PROBLEM_LIST_DETAILED = false
			await updateConfig()
		}

		return problemsDetailed
	} catch (err) {
		logger.info(err);
		throw err;
	}
}

async function fetchStatsFromLC() {
	try {
		const startTime = Date.now();
		const scriptName = path.basename(__filename)
		logger.info('')
		logger.time(`${scriptName} started...`)

		const problems = await fetchAllProblems();
		logger.info('Problem list length = ' + problems.length)
		logger.info('Problem at index 0 = ' + JSON.stringify(problems[0]))

		// const problemsDetailed = await fetchProblemsDetailed(problems)
		// logger.info('Detailed Problem list length = ' + problemsDetailed.length)

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
