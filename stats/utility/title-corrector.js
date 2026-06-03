const path = require('path')
const fs = require('fs').promises

async function readFromJSON() {
	try {
		const jsonPath = path.resolve(__dirname, '..', 'LC-API', 'generated', 'leetcode-problem-list.json')

		const jsonData = await fs.readFile(jsonPath, 'utf8')

		return JSON.parse(jsonData)
	} catch (err) {
		throw err
	}
}

async function updateFileTitles(problemList) {
	try {

		const dirPath = path.resolve(__dirname, 'title-correction-space')
		await fs.mkdir(dirPath, { recursive: true })

		const fileNames = await fs.readdir(dirPath)

		for (const fileName of fileNames) {
			const quesId = fileName.split('.')[0]
			const title = fileName.split('.')[1]
			const titleSuffix = title.substring(title.indexOf(' ') + 1)
			const extension = fileName.split('.')[2]

			const problemObj = problemList.find(({ questionFrontendId }) => questionFrontendId === quesId)
			if (!problemObj) {
				throw new Error(`No match found for ${fileName} in problem list`)
			}
			const newTitle = problemObj.titleSlug
			const newFileName = `${quesId}.${newTitle} ${titleSuffix}.${extension}`

			const filePath = path.join(dirPath, fileName)
			const newFilePath = path.join(dirPath, newFileName)

			await fs.rename(filePath, newFilePath)
			console.log(fileName + ' -> ' + newFileName)
		}
	} catch (err) {
		throw err
	}
}

async function titleCorrector() {
	try {
		const startTime = Date.now();
		console.log(`[${new Date().toISOString()}]: Title Corrector started.`);

		const problemList = await readFromJSON()
		// console.log(problemList.length)
		// console.log(problemList[0])

		await updateFileTitles(problemList)

		console.log(`[${new Date().toISOString()}]: Title Corrector completed.`);
		const endTime = Date.now();
		console.log(`Time Taken to correct titles = ${endTime - startTime} ms`);
	} catch (err) {
		console.log(err);
	}
}

titleCorrector()