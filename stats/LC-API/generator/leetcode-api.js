const path = require('node:path');
const fs = require('node:fs/promises');

const config = require('./config.json')

// don't forget to use await when calling this function
async function readFromJSON(filePath, defaultValue = []) {
	try {
		await fs.mkdir(path.dirname(filePath), { recursive: true });
		const problemsJSON = await fs.readFile(filePath, { encoding: "utf8" })

		return JSON.parse(problemsJSON)
	} catch (err) {
		if (err.code === 'ENOENT') {
			// console.log(`JSON file not found. Creating new file at: ${filePath}`);
			await fs.writeFile(filePath, JSON.stringify(defaultValue, null, 4));

			return defaultValue;
		}

		console.log(err)
		throw err
	}
}

// don't forget to use await when calling this function
async function writeToJSON(filePath, data) {
	try {
		await fs.mkdir(path.dirname(filePath), { recursive: true });
		await fs.writeFile(filePath, JSON.stringify(data, null, 4));
	} catch (err) {
		console.log(err)
		throw err
	}
}

// don't forget to use await when calling this function
async function createBackupJSON(sourceFilePath) {
	// ensure source file exists, create if missing
    try {
    	await fs.access(sourceFilePath);
    } catch (err) {
		if(err.code === "ENOENT"){
			console.log("Source file does not exist. No backup created");
			return null
		}
		throw err;
    }

	try {
		const backupDirPath = path.join(__dirname, '..', 'generated', 'backup');

		// ensure backup directory exists
		await fs.mkdir(backupDirPath, { recursive: true });

		const ext = path.extname(sourceFilePath);
		const sourceFileName = path.basename(sourceFilePath, ext);
		const timestamp = new Date().toISOString().replace(/[:.]/g, "-");
		const backupFileName = `${sourceFileName} [${timestamp}]${ext}`;
		const backupFilePath = path.join(backupDirPath, backupFileName)
		
		// create the backup file
		await fs.rename(sourceFilePath, backupFilePath);	
	} catch (err) {
		console.log(err)
		throw err
	}
}

async function fetchAllProblems() {
	try{
		const filePath = path.join(__dirname, '..', 'generated', config.PROBLEM_LIST_FILE);

		const lastUpdatedDatetime = new Date(config.LAST_UPDATED)

		// last update was less than 7 days ago; don't fetch new data from API
		if(!config.REFRESH_PROBLEM_LIST_JSON && 
			lastUpdatedDatetime.toString() !== "Invalid Date" && 
			Date.now() - lastUpdatedDatetime.getTime() < 7*24*60*60*1000){
			console.log('Using the local version of problem-list')

			return await readFromJSON(filePath)
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

		console.log('Fetching new problem list from Leetcode API...')

		const res = await fetch(config.BASE_URL, {
			method: "POST",
			headers: {
				"Content-Type": "application/json",
				"Origin": "https://leetcode.com",
				"Referer": "https://leetcode.com/problemset/",
				"User-Agent": "Mozilla/5.0"
			},
			body: JSON.stringify({ query })
		});

		if(!res.ok){
			const text = await res.text();
			console.log("Response body:", text);
			throw new Error(`HTTP ${res.status}`);
		}

		const { data, errors } = await res.json();

		if (errors) {
			console.log(errors);
			throw new Error("GraphQL error");
		}

		if (!data || !data.allQuestions) {
			throw new Error("Problems not found");
		}

		const problems = data.allQuestions

		problems.sort((a, b) => Number(a.questionFrontendId) - Number(b.questionFrontendId));

		// create a backup of the old json
		await createBackupJSON(filePath)

		await writeToJSON(filePath, problems)

		config.LAST_UPDATED = new Date().toISOString()
		
		const filePathConfig = path.join(__dirname, 'config.json');
		await writeToJSON(filePathConfig, config)

		console.log('Fetched problem list of length = ' + problems.length)

  		return problems
	}catch(err){
		console.log(err)
		throw err;
	}
}

function parseDetailedProblem(problem){
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
		description: problem.content,
		tags: problem.topicTags.map(tag => tag.name),
	};
}

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

		const res = await fetch(config.BASE_URL, {
			method: "POST",
			headers: {
				"Content-Type": "application/json",
				"Origin": "https://leetcode.com",
				"Referer": "https://leetcode.com/problems/",
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
			console.log(errors);
			throw new Error("GraphQL error");
		}

		if (!data || !data.question) {
			throw new Error("Problem not found");
		}

		return parseDetailedProblem(data.question);

	} catch (err) {
		console.log(err);
		throw err;
	}
}

const sleep = (time_ms = 250) => new Promise((resolve) => setTimeout(resolve, time_ms));

async function fetchProblemsDetailed(problems) {
	try{
		const filePath = path.join(__dirname, '..', 'generated', config.PROBLEM_LIST_DETAILED_FILE);
		let problemsDetailed = []
		
		if(config.REFRESH_PROBLEM_LIST_DETAILED_JSON){
			// create a backup of the old json
			await createBackupJSON(filePath)
			// clear the main json
			await writeToJSON(filePath, [])
		}else{
			problemsDetailed = await readFromJSON(filePath)
		}
		
		if(problems.length === problemsDetailed.length)return problemsDetailed
		else if(problems.length < problemsDetailed.length)throw new Error('Problems length mismatch')

		for(let i = problemsDetailed.length, limit = config.FETCH_NEXT_COUNT; 
			i < problems.length && limit > 0; 
			i++, limit--){
			const {questionFrontendId, title, titleSlug} = problems[i]
			console.log(`Fetching... ${questionFrontendId}.${title}`)

			problemsDetailed.push(await fetchProblemDetailed(titleSlug))

			await sleep(250) // prevent overwhelming the API
		}

		await writeToJSON(filePath, problemsDetailed)

		return problemsDetailed
	}catch(err){
		console.log(err);
		throw err;
	}
}

async function fetchStatsFromLC(){
	try {
		const startTime = Date.now();
		console.log(`[${new Date().toISOString()}]: Leetcode stat fetching Started.`);

		const problems = await fetchAllProblems();
		console.log('Problems[] length = ' + problems.length)

		const problemsDetailed = await fetchProblemsDetailed(problems)
		console.log('Detailed Problems[] length = ' + problemsDetailed.length)	

		console.log(`[${new Date().toISOString()}]: Leetcode stat fetching Completed.`);
		const endTime = Date.now();
		console.log(`Time Taken to fetch Leetcode stats = ${endTime - startTime} ms`);

	}catch(err) {
		console.error(err)
	}
}

fetchStatsFromLC()

// node ./stats/LC-API/generator/leetcode-api.js