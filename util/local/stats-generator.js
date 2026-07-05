const path = require('node:path');
const fs = require('node:fs/promises');

const logger = require('../logger.js')
const helper = require('../helper.js')
const config = require('./config.json')
const configExt = require('../config.json')
const langModel = require('./language-model.json');
const specialQuesIds = require('./special-ques-ids.json');

function getLangFormalName(langName) {
	for (const lang in langModel) {
		if (langModel[lang].name === langName) {
			return langModel[lang].formalName;
		}
	}

	return null;
}

function getLangNameFromDirPath(dirPath) {
	for (const lang in langModel) {
		for (const dirName of langModel[lang].dirNames) {
			if (dirName === path.basename(path.normalize(dirPath))) {
				return langModel[lang].name;
			}
		}
	}

	return null;
}

function updateCounterObj(obj, lang, isAccepted) {
	const updateAcceptedValBy = isAccepted ? 1 : 0;
	const updateUnacceptedValBy = !isAccepted ? 1 : 0;

	if (!obj[lang]) {
		obj[lang] = { accepted: 0, unaccepted: 0 };
	}

	obj[lang].accepted += updateAcceptedValBy;
	obj[lang].unaccepted += updateUnacceptedValBy;
}

// allowed chars = A-Z, a-z, 0-9, '-', '.', '[', ']', ' '
function hasInvalidChars(filename) {
	return /[^A-Za-z0-9.\[\]\- ]/.test(filename);
}

function isValidFilename(filename) {
	const regex = /^(?:(?:[1-9]\d{0,3})\.[A-Za-z0-9-]+\s+\[[1-9]\]|(?:[1-9]\d{0,3})\.[A-Za-z0-9-]+\s+\[(?:TLE|MLE)\s+(?:[1-9]\d{0,3})\s+of\s+(?:[1-9]\d{0,3})\]\s+\[[1-9]\])$/;

	return regex.test(filename);
}

async function generateStatsMap() {
	try {
		const dirPaths = [];
		for (const lang in langModel) {
			for (const dirName of langModel[lang].dirNames) {
				const dirPath = path.join(helper.ROOT, dirName)
				dirPaths.push(dirPath);
			}
		}

		const statsMap = new Map();

		for (const dirPath of dirPaths) {
			const fileNames = await fs.readdir(dirPath);

			for (const fileName of fileNames) {
				if (hasInvalidChars(fileName)) {
					logger.error(`Invalid characters found: "${fileName}"`)
					continue
				}

				if (!isValidFilename(path.parse(fileName).name)) {
					logger.error(`Invalid filename: "${fileName}"`)
					continue
				}

				const filePath = path.join(dirPath, fileName);

				const quesId = Number(fileName.split('.')[0]);
				const titleSlug = fileName.split('.')[1].split(' ')[0]
				const title = titleSlug.split('-').join(' ')
				const fileExtension = path.extname(filePath).substring(1);
				const language = getLangNameFromDirPath(dirPath);
				const isAccepted = !(fileName.includes('TLE') || fileName.includes('MLE'));

				if (!isAccepted) {
					logger.info(fileName)
				}

				let statObj = null;

				if (statsMap.has(quesId)) {
					statObj = statsMap.get(quesId);

					if (titleSlug !== statObj.titleSlug) {
						logger.error(`Title mismatch found: "${fileName}"`)
						continue
					}
				} else {
					statObj = { quesId, titleSlug, title, counter: {} };
				}

				updateCounterObj(statObj.counter, language, isAccepted);

				statsMap.set(quesId, statObj);
			}
		}

		return statsMap;

	} catch (err) {
		throw err
	}
}

function convertMapToArray(mp) {
	const arr = [];
	for (const [quesId, obj] of mp) {
		arr.push(obj);
	}

	arr.sort((a, b) => a.quesId - b.quesId);

	return arr;
}

function generateProblemCounters(problems) {
	// total problem accepted and unaccepted count
	const totalProblemCounter = { accepted: 0, unaccepted: 0 };

	// total accepted and unaccepted count per language
	const problemCounterPerLang = {};

	// total files per language
	const fileCounter = {};

	for (const lang in langModel) {
		problemCounterPerLang[lang] = { accepted: 0, unaccepted: 0 };

		fileCounter[lang] = 0;
	}

	for (const problem of problems) {
		const { quesId, counter } = problem;

		let isAccepted = false;
		let type = 'general';

		for (const lang in counter) {
			problemCounterPerLang[lang].accepted += counter[lang].accepted > 0 ? 1 : 0;
			problemCounterPerLang[lang].unaccepted += counter[lang].accepted === 0 && counter[lang].unaccepted > 0 ? 1 : 0;

			fileCounter[lang] += counter[lang].accepted + counter[lang].unaccepted;

			if (counter[lang].accepted > 0) {
				isAccepted = true;
			}

			if (langModel[lang].types.includes("database")) {
				type = 'database';
			} else if (specialQuesIds.JSTS.includes(quesId)) {
				type = 'javascript/typescript';
			}
		}

		if (isAccepted) {
			totalProblemCounter.accepted++;
			problem.isAccepted = true;
		} else {
			totalProblemCounter.unaccepted++;
			problem.isAccepted = false;
		}

		problem.type = type;
	}

	return { totalProblemCounter, problemCounterPerLang, fileCounter };
}

async function generateProblemsJSON(problems) {
	try {
		let problemsStringified = '';
		problemsStringified += '[\n';
		problemsStringified +=
			problems
				.map((problem) => JSON.stringify(problem, null, '\t'))
				.join(',\n');
		problemsStringified += '\n]\n';

		await helper.ensureFileDir('LCProblemsList')
		const filePathJSON = helper.getFilePath('LCProblemsList')

		await fs.writeFile(filePathJSON, problemsStringified);

	} catch (err) {
		throw err
	}
}

async function generateMDlinksFile(problems) {
	try {
		for (const lang in langModel) {
			const problemsAccepted =
				problems
					.filter(({ isAccepted, counter }) => isAccepted && counter[lang]);

			let fileDataStringified = '';
			fileDataStringified += '| Id | Title | Link(s) | Type |\n';
			fileDataStringified += '| --- | --- | --- | --- |\n';

			for (const problem of problemsAccepted) {
				const { quesId, titleSlug, title, counter, type } = problem;

				fileDataStringified += `|${quesId} | ${title} |`;

				const { extension, dirNames } = langModel[lang];
				let dirIdx = 0;
				if (dirNames.length > 1) {
					dirIdx = Number.isInteger(quesId / 500) ? Math.floor(quesId / 500) - 1 : Math.floor(quesId / 500);
				}
				const dirName = dirNames[dirIdx];

				for (let i = 1; i <= counter[lang].accepted; i++) {
					const url = `<../../${dirName}/${quesId}.${titleSlug} [${i}].${extension}>`;
					fileDataStringified += `[L${i}](${url}) `;
				}

				fileDataStringified += `|${type}|\n`;
			}

			await helper.ensureDir('linkTables')
			const filePathMD = path.join(helper.getDirPath('linkTables'), `leetcode-links-${lang}.md`);

			await fs.writeFile(filePathMD, fileDataStringified);
		}

	} catch (err) {
		throw err;
	}
}

async function updateDatabaseQuesIds(problems) {
	try {
		const quesIdsDB = problems
			.filter(({ type }) => type === 'database')
			.map(({ quesId }) => quesId);

		const filePathJSON = helper.getFilePath('specialQuesIds')

		specialQuesIds['DB'] = quesIdsDB

		await fs.writeFile(filePathJSON, JSON.stringify(specialQuesIds, null, 4), "utf8");

	} catch (err) {
		throw err;
	}
}

async function updateStatsinReadmeFile(totalProblemCounter, problemCounterPerLang) {
	try {
		const filePath = path.join(helper.ROOT, 'README.md');
		const seperator = "<!-- UPDATE STATS HERE -->";

		const fileData = await fs.readFile(filePath, { encoding: "utf8" });
		const fileDataArr = fileData.split(seperator);

		let statData = '';
		statData += `Last updated at _${new Date().toUTCString()}_\n\n`;
		statData += `_${new Date().toString()}_\n`;

		statData += '### Total problems:\n';
		statData += '| Accepted | Partially accepted | Out of |\n';
		statData += '| --- | --- | --- |\n';
		statData += `| ${totalProblemCounter.accepted} | ${totalProblemCounter.unaccepted} | ${config.MAX_QUES_ID} |\n`;

		statData += '### Total problems solved per language:\n';
		statData += '| Language  | Accepted | Partially accepted | Links Table |\n';
		statData += '| --- | --- | --- | --- |\n';

		for (language in problemCounterPerLang) {
			const acceptedCount = problemCounterPerLang[language].accepted;
			const unacceptedCount = problemCounterPerLang[language].unaccepted;

			const url = `${configExt.dirPaths.linkTables}/leetcode-links-${language}.md`;

			statData += `| ${getLangFormalName(language)} | ${acceptedCount} | ${unacceptedCount} | [click](${url})\n`;
		}

		const updatedFileData =
			fileDataArr[0] +
			seperator +
			"\n" +
			statData +
			seperator +
			fileDataArr[fileDataArr.length - 1];

		await fs.writeFile(filePath, updatedFileData);

	} catch (err) {
		throw err;
	}
}

async function generateStats() {
	try {
		const startTime = Date.now();
		logger.info('')
		logger.time('Problem Stat Generation Started...');

		const statsMap = await generateStatsMap();

		const problems = convertMapToArray(statsMap);
		logger.info(`Problems list length = ${problems.length}`)
		logger.info(`Problem at index 0 = ${JSON.stringify(problems[0])}`)

		const { totalProblemCounter, problemCounterPerLang, fileCounter } =
			generateProblemCounters(problems);

		logger.info(`Total problem counter = ${JSON.stringify(totalProblemCounter)}`);
		logger.info(`Problem counter per language = ${JSON.stringify(problemCounterPerLang)}`);
		logger.info(`File counter = ${JSON.stringify(fileCounter)}`);

		await generateProblemsJSON(problems);

		await generateMDlinksFile(problems);

		await updateDatabaseQuesIds(problems);

		await updateStatsinReadmeFile(totalProblemCounter, problemCounterPerLang);

		if (logger.STATE.errorFound) {
			console.log('Issue(s) found during execution: check logs')
		}
		logger.time('Problem Stat Generation Completed.');

		const endTime = Date.now();
		logger.time(`Time Taken to Generate Problem stats = ${endTime - startTime} ms`);

	} catch (err) {
		console.error(err);
		logger.error(err);
	}
}

generateStats();

// Depreciated
// function generateCSVfile(statsArr) {
// 	return new Promise(async (resolve, reject) => {
// 		try {
// 			let statsStringified = ''
// 			statsStringified += 'Id,Title,Type,Language(s),accepted,partially-accepted\n';

// 			for (const statObj of statsArr) {
// 				const { quesId, title, counter, type } = statObj;

// 				const titleWithOutCommas = title.replace(/,/g, '*');

// 				let languagesStr = '';
// 				let acceptedStr = '';
// 				let unacceptedStr = '';

// 				for (const language in counter) {
// 					languagesStr += language + '+';
// 					acceptedStr += counter[language].accepted + '+';
// 					unacceptedStr += (counter[language].unaccepted ?? 0) + '+';
// 				}

// 				// remove the trailing '+' sign
// 				languagesStr = languagesStr.slice(0, -1);
// 				acceptedStr = acceptedStr.slice(0, -1);
// 				unacceptedStr = unacceptedStr.slice(0, -1);

// 				statsStringified += `${quesId},${titleWithOutCommas},${type},${languagesStr},${acceptedStr},${unacceptedStr}\n`;
// 			}

// 			const filePath = path.join(__dirname, '..', 'generated', 'leetcode-stats.csv');
// 			await fs.writeFile(filePath, statsStringified);

// 			resolve();
// 		} catch (err) {
// 			console.log(err);
// 			reject();
// 		}
// 	});
// }
