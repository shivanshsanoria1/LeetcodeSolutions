const path = require('node:path');
const fs = require('node:fs/promises');

async function compareLists() {
	try {
		const myFilePath = path.join(__dirname, '..', 'generated', 'leetcode-stats-array.json')
		const myData = await fs.readFile(myFilePath, { encoding: "utf8" })
		const myProblems = JSON.parse(myData)

		const lcFilePath = path.join(__dirname, '..', 'LC-API', 'generated', 'leetcode-problem-list.json')
		const lcData = await fs.readFile(lcFilePath, { encoding: "utf8" })
		const lcProblems = JSON.parse(lcData)
		
		const mismatchedProblems = []
		for(const myProblem of myProblems){
			const myTitle = myProblem.title.toLowerCase()
			const mySlug = myProblem.title.replace(/ /g, '-').toLowerCase()

			const lcProblem = lcProblems.find((lcProblem) => Number(lcProblem.questionFrontendId) === myProblem.quesId)
			if(!lcProblem){
				console.log(`id ${myProblem.quesId} not found in official LC json`)
				continue
			}
			const lcTitle = lcProblem.title.trim().replace(/-/g, ' ').toLowerCase()

			const titleMatch = myTitle === lcTitle
			const slugMatch = mySlug === lcProblem.titleSlug

			if(!titleMatch){
				mismatchedProblems.push({
					id: myProblem.quesId,
					myTitle,
					lcTitle: lcProblem.title,
					// titleMatch,
					newTitle: lcTitle.replace(/ /g, '_'),
					lcTitleSlug: lcProblem.titleSlug,
					// slugMatch,
					langs: Object.keys(myProblem.counter).join(',')
				})
			}
		}

		console.log(mismatchedProblems.length + ' mismatches found.')

		const mismatchedProblemsFilePath = path.join(__dirname, 'generated', 'mismatched-data.json')
		await fs.writeFile(mismatchedProblemsFilePath, JSON.stringify(mismatchedProblems, null, 4), 'utf-8');

	} catch (err) {
		throw err
	}
}

compareLists()