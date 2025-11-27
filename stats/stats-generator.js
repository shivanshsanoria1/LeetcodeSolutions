const path = require("node:path");
const fs = require("node:fs/promises");

const {languageModel} = require('./language-model.js')
const {quesIdSetJSTS} = require('./ques-id-set-JS-TS.js')

function getLangFormalName(langName) {
  for(const lang in languageModel){
    if(languageModel[lang].name === langName){
      return languageModel[lang].formalName
    }
  }

  return null
}

function getLanguageNameFromDirPath(_dirPath){
  for(const lang in languageModel){
    for(const dirPath of languageModel[lang].dirPaths){
      if(dirPath === _dirPath){
        return languageModel[lang].name
      }
    }
  }

  return null
}

function updateCounterObj(obj, lang, isAccepted) {
  const updateAcceptedValBy = isAccepted ? 1 : 0;
  const updateUnacceptedValBy = !isAccepted ? 1 : 0;

  if(!obj[lang]){
    obj[lang] = languageModel[lang].type === 'database' ? {accepted: 0} : {accepted: 0, unaccepted: 0}
  }
  
  obj[lang].accepted += updateAcceptedValBy;

  if(obj[lang].unaccepted != null){
    obj[lang].unaccepted += updateUnacceptedValBy; 
  }
}

function generateStatsMap() {
  return new Promise(async (resolve, reject) => {
    try {
      const dirPaths = []
      for(const lang in languageModel){
        for(const dirPath of languageModel[lang].dirPaths){
          dirPaths.push(dirPath)
        }
      }

      const statsMap = new Map();

      for (const dirPath of dirPaths) {
        const fileNames = await fs.readdir(dirPath);

        for (const fileName of fileNames) {
          const filePath = path.join(dirPath, fileName);

          const quesId = parseInt(fileName.split('.')[0]);
          const title = fileName.split('.')[1].split(' ')[0].split('_').join(' ');
          const fileExtension = path.extname(filePath).substring(1);
          const language = getLanguageNameFromDirPath(dirPath)
          const isAccepted = fileName.search('TLE') === -1 && fileName.search('MLE') === -1;

          let statObj = null;

          if (statsMap.has(quesId)) {
            statObj = statsMap.get(quesId);
          } else {
            statObj = {
              quesId,
              title,
              counter: {},
            };
          }

          updateCounterObj(statObj.counter, language, isAccepted);
          statsMap.set(quesId, statObj);
        }
      }

      resolve(statsMap);
    } catch (err) {
      console.log(err);
      reject();
    }
  });
}

function convertMapToArray(mp) {
  const arr = []
  for (const [quesId, obj] of mp) {
    arr.push(obj)
  }

  arr.sort((a, b) => a.quesId - b.quesId)

  return arr
}

function generateTotalProblemCounterAndUpdateStatsArray(statsArr) {
  // total problem accepted and unaccepted count
  const totalProblemCount = {
    accepted: 0,
    unaccepted: 0,
  };

  // total accepted and unaccepted count per language
  const totalLanguageCounter = {}

  // total files per language
  const fileCounter = {}

  for(const lang in languageModel){
    if(languageModel[lang].type === 'database'){
      totalLanguageCounter[lang] = { accepted: 0 }
    }else{
      totalLanguageCounter[lang] = { accepted: 0, unaccepted: 0 }
    }

    fileCounter[lang] = 0
  }

  for (const obj of statsArr) {
    const {quesId, counter} = obj

    let isAccepted = false;
    let type = 'general'

    for (const lang in counter) {
      totalLanguageCounter[lang].accepted += counter[lang].accepted > 0 ? 1 : 0;

      if(counter[lang].accepted === 0 && counter[lang].unaccepted) {
        totalLanguageCounter[lang].unaccepted += counter[lang].unaccepted > 0 ? 1 : 0;
      }

      fileCounter[lang] += counter[lang].accepted + (counter[lang].unaccepted ?? 0);

      if (counter[lang].accepted > 0) {
        isAccepted = true;
      }

      if (languageModel[lang].type === 'database') {
        type = 'database'
      }else if(quesIdSetJSTS.has(quesId)){
        type = 'javascript/typescript'
      }
    }

    if (isAccepted) {
      totalProblemCount.accepted++;
      obj.isAccepted = true;
    } else {
      totalProblemCount.unaccepted++;
      obj.isAccepted = false;
    }

    obj.type = type;
  }

  return { totalProblemCount, totalLanguageCounter, fileCounter };
}

function generateJSfile(statsArr) {
  return new Promise(async (resolve, reject) => {
    try {
      let statsArrStringified = 'const statsArr = [\n';
      statsArrStringified += 
        statsArr
        .map((statObj) => JSON.stringify(statObj, null, '\t'))
        .join(',\n');
      statsArrStringified += '\n]\n';

      const filePath = path.join(__dirname, 'generated', 'leetcode-stats-array.js');
      await fs.writeFile(filePath, statsArrStringified);

      resolve();
    } catch (err) {
      console.log(err);
      reject();
    }
  });
}

function generateCSVfile(statsArr) {
  return new Promise(async (resolve, reject) => {
    try {
      let statsStringified = 'S.No.,Title,Type,Language(s),accepted,partially-accepted\n';

      for (const statObj of statsArr) {
        const { quesId, title, counter, type } = statObj;

        const titleWithOutCommas = title.replace(/,/g, "*");

        let languagesStr = "";
        let acceptedStr = "";
        let unacceptedStr = "";

        for (const language in counter) {
          languagesStr += language + "+";
          acceptedStr += counter[language].accepted + "+";
          unacceptedStr += (counter[language].unaccepted ?? 0) + "+";
        }

        // remove the trailing '+' sign
        languagesStr = languagesStr.slice(0, -1);
        acceptedStr = acceptedStr.slice(0, -1);
        unacceptedStr = unacceptedStr.slice(0, -1);

        statsStringified += `${quesId},${titleWithOutCommas},${type},${languagesStr},${acceptedStr},${unacceptedStr}\n`;
      }

      const filePath = path.join(__dirname, 'generated', 'leetcode-stats.csv');
      await fs.writeFile(filePath, statsStringified);

      resolve();
    } catch (err) {
      console.log(err);
      reject();
    }
  });
}

function generateMDlinksFile(statsArr){
  return new Promise(async (resolve, reject) => {
    try {
      let fileDataStringified = '| S.No. | Title | Link(s) |\n';
      fileDataStringified += '| --- | --- | --- |\n'

      for (const statObj of statsArr) {
        const { quesId, title, counter } = statObj;

        const titleInFile = title.split(' ').join('_')
        const titleWithOutCommas = title.replace(/,/g, "*");

        fileDataStringified += `|${quesId} | ${titleWithOutCommas} |`

        for (const lang in counter) {
          const {extension, dirNames} = languageModel[lang]
          let dirIdx = 0
          if(dirNames.length > 1){
            dirIdx = Number.isInteger(quesId / 500) ? Math.floor(quesId / 500) - 1 : Math.floor(quesId / 500)
          }
          const dirName = dirNames[dirIdx]

          for(let i=1; i<=counter[lang].accepted; i++){
            fileDataStringified += `[${lang}${i}](<../../${dirName}/${quesId}.${titleInFile} [${i}].${extension}>) `
          }
        }

        fileDataStringified += '|\n'
      }

      const filePath = path.join(__dirname, 'generated', 'leetcode-links.md');
      await fs.writeFile(filePath, fileDataStringified);

      resolve();

    } catch (err) {
      console.log(err);
      reject();
    }
  });
}

function generateDatabaseQuesIdSetFile(statsArr) {
  return new Promise(async (resolve, reject) => {
    try {
      const quesIds = statsArr.filter(({type}) => type === 'database')

      let quesIdsStringified = '// Set containing the ques ids of problems of type "database"\n'
      quesIdsStringified += `// Set size = ${quesIds.length}\n\n`
      quesIdsStringified += 'const quesIdSet = new Set([\n';
      quesIdsStringified += 
        quesIds
        .map(({quesId}) => quesId)
        .join(',\n');
      quesIdsStringified += '\n])\n';

      const filePath = path.join(__dirname, 'generated', 'ques-id-set-database.js');
      await fs.writeFile(filePath, quesIdsStringified);

      resolve();
    } catch (err) {
      console.log(err);
      reject();
    }
  });
}

async function updateStatsinReadmeFile(totalProblemCount, totalLanguageCounter) {
  return new Promise(async (resolve, reject) => {
    try {
      const filePath = path.join(__dirname, '..', 'README.md');
      const seperator = '<!-- STATS -->'

      const fileData = await fs.readFile(filePath, { encoding: 'utf8' })
      const fileDataArr = fileData.split(seperator)

      let statData = '## Stats\n'
      statData += `Last updated on _${new Date().toUTCString()}_\n`

      statData += '### Total problems solved:\n'
      statData += '| Accepted | Partially accepted |\n'
      statData += '| --- | --- |\n'
      statData += `| ${totalProblemCount.accepted} | ${totalProblemCount.unaccepted} |\n`

      statData += '### Total problems solved per language:\n'
      statData += '| Language  | Accepted | Partially accepted |\n'
      statData += '| --- | --- | --- |\n'

      for (language in totalLanguageCounter) {
        const acceptedCount = totalLanguageCounter[language].accepted;
        const unacceptedCount = totalLanguageCounter[language].unaccepted ?? 0;

        statData += `| ${getLangFormalName(language)} | ${acceptedCount} | ${unacceptedCount} |\n`;
      }
      
      const updatedFileData = fileDataArr[0] + seperator + '\n' + statData + seperator + fileDataArr[fileDataArr.length - 1]

      await fs.writeFile(filePath, updatedFileData)

      resolve();
    } catch (err) {
      console.log(err);
      reject();
    }
  });
}

async function generateStats() {
  try {
    const startTime = Date.now();
    console.log(`Solutions Stat Generation Started at: ${new Date().toISOString()}`);

    const statsMap = await generateStatsMap();

    const statsArr = convertMapToArray(statsMap);

    const { totalProblemCount, totalLanguageCounter, fileCounter } =
      generateTotalProblemCounterAndUpdateStatsArray(statsArr);

    console.log(totalProblemCount);
    console.log(totalLanguageCounter);
    console.log(fileCounter);

    await generateJSfile(statsArr);

    await generateCSVfile(statsArr);

    await generateMDlinksFile(statsArr)

    await generateDatabaseQuesIdSetFile(statsArr)

    await updateStatsinReadmeFile(totalProblemCount, totalLanguageCounter);

    console.log(`Solutions Stat Generation Completed at: ${new Date().toISOString()}`);
    const endTime = Date.now();
    console.log(`Time Taken to Generate Solution stats = ${endTime - startTime} ms`);
  } catch (err) {
    console.log(err);
  }
}

// console.log('Count of JS/TS specific questions = ' + quesIdSetJSTS.size)
generateStats()