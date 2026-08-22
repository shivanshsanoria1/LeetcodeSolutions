const path = require('path')
const fs = require('fs').promises

const logger = require('../logger.js')

async function readFromJSON() {
	try {
		const jsonPath = path.resolve(__dirname, '..', 'web', 'generated', 'leetcode-problem-list.json')
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
		// sort in increasing order of quesId
		fileNames.sort((a, b) => parseInt(a.split('.')[0]) - parseInt(b.split('.')[0]))

		for (const fileName of fileNames) {
			const quesId = fileName.split('.')[0]
			const titleWithSuffix = fileName.split('.')[1]
			const title = titleWithSuffix.split(' ')[0]
			const titleSuffix = titleWithSuffix.substring(titleWithSuffix.indexOf(' ') + 1)
			const extension = fileName.split('.')[2]

			const problemObj = problemList.find(({ questionFrontendId }) => questionFrontendId === quesId)
			if (!problemObj) {
				throw new Error(`No match found for ${fileName} in problem list`)
			}

			const newTitle = problemObj.titleSlug
			if (title === newTitle) {
				logger.info(`${fileName} -> already upto date`)
				continue
			}

			const newFileName = `${quesId}.${newTitle} ${titleSuffix}.${extension}`

			const filePath = path.join(dirPath, fileName)
			const newFilePath = path.join(dirPath, newFileName)
			await fs.rename(filePath, newFilePath)

			logger.info(fileName + ' -> ' + newFileName)
		}
	} catch (err) {
		throw err
	}
}

async function titleCorrector() {
	try {
		const startTime = Date.now();
		logger.time('Title Corrector started.');

		const problemList = await readFromJSON()
		// console.log(problemList.length)
		// console.log(problemList[0])

		await updateFileTitles(problemList)

		logger.time('Title Corrector completed.');
		const endTime = Date.now();
		console.log(`Time Taken to correct titles = ${endTime - startTime} ms`);
	} catch (err) {
		console.error(err);
	}
}

titleCorrector()