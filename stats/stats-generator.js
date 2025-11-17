const path = require("node:path");
// const { readdir, writeFile, appendFile } = require("node:fs/promises");
const fs = require("node:fs/promises");

const languages = {
  cpp: {
    name: 'cpp',
    formalName: 'C++',
    extension: 'cpp',
    type: 'general',
    dirPaths: [
      path.join(__dirname, '..', 'CPP [1-500]'),
      path.join(__dirname, '..', 'CPP [501-1000]'),
      path.join(__dirname, '..', 'CPP [1001-1500]'),
      path.join(__dirname, '..', 'CPP [1501-2000]'),
      path.join(__dirname, '..', 'CPP [2001-2500]'),
      path.join(__dirname, '..', 'CPP [2501-3000]'),
      path.join(__dirname, '..', 'CPP [3001-3500]'),
      path.join(__dirname, '..', 'CPP [3501-4000]'),
    ]
  },
  js: {
    name: 'js',
    formalName: 'Javascript',
    extension: 'js',
    type: 'general',
    dirPaths: [path.join(__dirname, '..', 'JS')]
  },
  mysql: {
    name: 'mysql',
    formalName: 'MySQL',
    extension: 'sql',
    type: 'database',
    dirPaths: [path.join(__dirname, '..', 'MYSQL')]
  },
}

function getLangFormalName(langName) {
  for(const lang in languages){
    if(languages[lang].name === langName){
      return languages[lang].formalName
    }
  }

  return null
}

function getLanguageNameFromDirPath(_dirPath){
  for(const lang in languages){
    for(const dirPath of languages[lang].dirPaths){
      if(dirPath === _dirPath){
        return languages[lang].name
      }
    }
  }

  return null
}

function updateCounterObj(obj, lang, isAccepted) {
  const updateAcceptedValBy = isAccepted ? 1 : 0;
  const updateUnacceptedValBy = !isAccepted ? 1 : 0;

  if(!obj[lang]){
    obj[lang] = {accepted: 0, unaccepted: 0}
  }
  
  obj[lang].accepted += updateAcceptedValBy;
  obj[lang].unaccepted += updateUnacceptedValBy; 
}

function generateStatsMap() {
  return new Promise(async (resolve, reject) => {
    try {
      const dirPaths = []
      for(const lang in languages){
        for(const dirPath of languages[lang].dirPaths){
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
  const arr = [];

  for (const [quesId, obj] of mp) {
    arr.push(obj);
  }

  arr.sort((a, b) => a.quesId - b.quesId);

  return arr;
}

function generateTotalProblemCounterAndUpdateStatsArray(arr) {
  // total problem accepted and unaccepted count
  const totalProblemCount = {
    accepted: 0,
    unaccepted: 0,
  };

  // total accepted and unaccepted count per language
  const totalLanguageCounter = {}

  // total files per language
  const fileCounter = {}

  for(const lang in languages){
    if(languages[lang].type === 'database'){
      totalLanguageCounter[lang] = { accepted: 0 }
    }else{
      totalLanguageCounter[lang] = { accepted: 0, unaccepted: 0 }
    }

    fileCounter[lang] = 0
  }

  for (const obj of arr) {
    const counter = obj.counter;
    let isAccepted = false;
    let type = "general";

    for (const lang in counter) {
      totalLanguageCounter[lang].accepted +=
        counter[lang].accepted > 0 ? 1 : 0;

      if (
        counter[lang].accepted === 0 &&
        totalLanguageCounter[lang].unaccepted !== undefined &&
        counter[lang].unaccepted !== undefined
      ) {
        totalLanguageCounter[lang].unaccepted +=
          counter[lang].unaccepted > 0 ? 1 : 0;
      }

      fileCounter[lang] +=
        counter[lang].accepted + (counter[lang].unaccepted ?? 0);

      if (counter[lang].accepted > 0) {
        isAccepted = true;
      }

      if (languages[lang].type === 'database') {
        type = "database";
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
      statsArrStringified += '\n]\n\n';
      statsArrStringified += 'export default statsArrStringified';

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
      let statsStringified = 'quesId,Title,Language(s),accepted,partially-accepted\n';

      for (const statObj of statsArr) {
        const { quesId, title, counter } = statObj;

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

        statsStringified += `${quesId},${titleWithOutCommas},${languagesStr},${acceptedStr},${unacceptedStr}\n`;
      }

      const filePath = path.join(__dirname, "generated", `leetcode-stats.csv`);
      await fs.writeFile(filePath, statsStringified);

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

    await updateStatsinReadmeFile(totalProblemCount, totalLanguageCounter);

    console.log(`Solutions Stat Generation Completed at: ${new Date().toISOString()}`);
    const endTime = Date.now();
    console.log(`Time Taken to Generate Solution stats = ${endTime - startTime} ms`);
  } catch (err) {
    console.log(err);
  }
}

generateStats();
