const path = require('node:path');
const fs = require('node:fs/promises');

const URL = "https://leetcode.com/graphql";

async function fetchAllProblems() {
	try{
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

		const res = await fetch(URL, {
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

		const json = await res.json();
		if (json.errors) {
			console.log(json.errors);
			throw new Error("GraphQL error");
		}

  		return json.data.allQuestions;
	}catch(err){
		console.log(err)
	}
	
	return []
}

async function writeToJSON(problemsJSON) {
	try {
		problemsJSON.sort((a, b) => Number(a.questionFrontendId) - Number(b.questionFrontendId));

		const filePathJSON = path.join(__dirname, '..', 'generated', 'leetcode-stats-official.json');

		await fs.writeFile(filePathJSON, JSON.stringify(problemsJSON, null, 4));
	} catch (err) {
		console.log(err)
	}
}

async function fetchStatsFromLC(){
	try {
		const startTime = Date.now();
		console.log(`[${new Date().toISOString()}]: Leetcode stat fetching Started.`);

		const problemsJSON = await fetchAllProblems();

		await writeToJSON(problemsJSON);

		console.log(`[${new Date().toISOString()}]: Leetcode stat fetching Completed.`);
		const endTime = Date.now();
		console.log(`Time Taken to fetch Leetcode stats = ${endTime - startTime} ms`);

	}catch(err) {
		console.log(err)
	}
}

fetchStatsFromLC()

// node ./stats/LC-API/generator/leetcode-api.js