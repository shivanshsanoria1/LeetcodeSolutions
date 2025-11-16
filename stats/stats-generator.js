const path = require('node:path');
const { readdir, writeFile, appendFile } = require('node:fs/promises');

function extensionToLanguage(extension){
    extension = extension.toLowerCase()
    language = null

    switch(extension){
        case 'cpp':
            language = 'cpp'
            break
        case 'js':
            language = 'js'
            break
        case 'sql':
            language = 'mysql'
            break
        default:
            language = ''
    }

    return language
}

function updateCounterObj(obj, language, isAccepted){
    const updateAcceptedValBy = isAccepted ? 1 : 0
    const updateUnacceptedValBy = !isAccepted ? 1 : 0

    switch(language){
        case 'cpp':
            if(obj.cpp){
                obj.cpp.accepted += updateAcceptedValBy
                obj.cpp.unaccepted += updateUnacceptedValBy
            }else{
                obj.cpp = {accepted: updateAcceptedValBy, unaccepted: updateUnacceptedValBy}
            }
            break

        case 'js':
            if(obj.js){
                obj.js.accepted += updateAcceptedValBy
                obj.js.unaccepted += updateUnacceptedValBy
            }else{
                obj.js = {accepted: updateAcceptedValBy, unaccepted: updateUnacceptedValBy}
            }
            break

        case 'mysql':
            if(obj.mysql){
                obj.mysql.accepted += updateAcceptedValBy
            }else{
                obj.mysql = {accepted: updateAcceptedValBy}
            }
            break
    }
}

function generateStatsMap(){
  return new Promise(async(resolve, reject) => {
    try{
      const dirPath_cpp_0001_0500 = path.join(__dirname, '..', 'CPP [1-500]')
      const dirPath_cpp_0501_1000 = path.join(__dirname, '..', 'CPP [501-1000]')
      const dirPath_cpp_1001_1500 = path.join(__dirname, '..', 'CPP [1001-1500]')
      const dirPath_cpp_1501_2000 = path.join(__dirname, '..', 'CPP [1501-2000]')
      const dirPath_cpp_2001_2500 = path.join(__dirname, '..', 'CPP [2001-2500]')
      const dirPath_cpp_2501_3000 = path.join(__dirname, '..', 'CPP [2501-3000]')
      const dirPath_cpp_3001_3500 = path.join(__dirname, '..', 'CPP [3001-3500]')
      const dirPath_cpp_3501_4000 = path.join(__dirname, '..', 'CPP [3501-4000]')
      const dirPath_js = path.join(__dirname, '..', 'JS')
      const dirPath_mysql = path.join(__dirname, '..', 'MYSQL')
      
      const dirPaths = [
        dirPath_cpp_0001_0500,
        dirPath_cpp_0501_1000,
        dirPath_cpp_1001_1500,
        dirPath_cpp_1501_2000,
        dirPath_cpp_2001_2500,
        dirPath_cpp_2501_3000,
        dirPath_cpp_3001_3500,
        dirPath_cpp_3501_4000,
        dirPath_js, 
        dirPath_mysql
      ]

      const statsMap = new Map()

      for(const dirPath of dirPaths){
        const fileNames = await readdir(dirPath)
  
        for(const fileName of fileNames){
          const filePath = path.join(dirPath, fileName)
  
          const quesId = parseInt(fileName.split('.')[0])
          const title = fileName.split('.')[1].split(' ')[0].split('_').join(' ')
          const fileExtension = path.extname(filePath).substring(1)
          const language = extensionToLanguage(fileExtension)
          const isAccepted = fileName.search('TLE') === -1 && fileName.search('MLE') === -1
          
          let statObj = null 
          
            if(statsMap.has(quesId)){
                statObj = statsMap.get(quesId)
            }else{
                statObj = {
                    quesId,
                    title,
                    counter: {}
                }
            }

          updateCounterObj(statObj.counter, language, isAccepted)
          statsMap.set(quesId, statObj)
        }
      }

      resolve(statsMap)

    }catch(err){
      console.log(err)
      reject()
    }
  })
}

function convertMapToArray(mp){
  const arr = []

  for(const [quesId, obj] of mp){
    arr.push(obj)
  }

  arr.sort((a, b) => a.quesId - b.quesId)

  return arr
}

function generateTotalProblemCounter(arr){
    // total problem accepted and unaccepted count 
    const totalProblemCount = {
        accepted: 0,
        unaccepted: 0,
    }

    // total accepted and unaccepted count per language
    const totalLanguageCounter = {
        cpp: {accepted: 0, unaccepted: 0},
        js: {accepted: 0, unaccepted: 0},
        mysql: {accepted: 0},
    }

    // total files per language
    const fileCounter = {
        cpp: 0,
        js: 0,
        mysql: 0,
    }

    for(const obj of arr){
        const counter = obj.counter
        let isAccepted = false

        for(const language in counter){
            if(counter[language].accepted > 0){
                isAccepted = true
            }

            totalLanguageCounter[language].accepted += counter[language].accepted > 0 ? 1 : 0

            if(counter[language].accepted === 0 && 
                totalLanguageCounter[language].unaccepted !== undefined && 
                counter[language].unaccepted !== undefined){
                totalLanguageCounter[language].unaccepted += counter[language].unaccepted > 0 ? 1 : 0
            }

            fileCounter[language] += counter[language].accepted + (counter[language].unaccepted ?? 0)
        }

        if(isAccepted){
            totalProblemCount.accepted++
            obj.isAccepted = true
        }else{
            totalProblemCount.unaccepted++
            obj.isAccepted = false
        }
    }

    return {totalProblemCount, totalLanguageCounter, fileCounter}
}

function getFullLanguageName(language){
  let fullLanguage = null

  switch(language){
    case 'cpp':
      fullLanguage = 'C++'
      break
    case 'js':
      fullLanguage = 'Javascript'
      break
    case 'mysql':
      fullLanguage = 'MySQL'
      break
    default:
      fullLanguage = ''
  }

  return fullLanguage
}

function generateJSFile(statsArr){
  return new Promise(async(resolve, reject) => {
    try{
      let statsArrStringified = 'const statsArr = [\n'
      statsArrStringified += statsArr.map((statObj) => JSON.stringify(statObj, null, '\t')).join(',\n')
      statsArrStringified += '\n]\n\n'
      statsArrStringified += 'export default statsArrStringified'

      const filePath = path.join(__dirname, 'generated', `leetcode-stats-array.js`)
      await writeFile(filePath, statsArrStringified)

      resolve()
    }catch(err){
      console.log(err)
      reject()
    }
  })
}

function generateCSVFile(statsArr) {
  return new Promise(async(resolve, reject) => {
    try{
      let statsStringified = 'quesId,Title,Language(s),accepted,partially-accepted\n'

      for(const statObj of statsArr){
        const {
          quesId, 
          title, 
          counter
        } = statObj

        const titleWithOutCommas = title.replace(/,/g, '*')
        
        let languagesStr = ''
        let acceptedStr = ''
        let unacceptedStr = ''

        for(const language in counter){
          languagesStr += language + '+'
          acceptedStr += counter[language].accepted + '+'
          unacceptedStr += (counter[language].unaccepted ?? 0) + '+'
        }

        // remove the trailing '+' sign
        languagesStr = languagesStr.slice(0, -1)
        acceptedStr = acceptedStr.slice(0, -1)
        unacceptedStr = unacceptedStr.slice(0, -1)
        
        statsStringified += `${quesId},${titleWithOutCommas},${languagesStr},${acceptedStr},${unacceptedStr}\n`
      }

      const filePath = path.join(__dirname, 'generated', `leetcode-stats.csv`)
      await writeFile(filePath, statsStringified)

      resolve()
    }catch(err){
      console.log(err)
      reject()
    }
  })
}

async function updateStatsinReadmeFile(totalProblemCount, totalLanguageCounter){
  return new Promise(async(resolve, reject) => {
    try{
      const filePath = path.join(__dirname, '..', 'README.md')

      let statData = '## Stats\n'
      // statData += '@@@@@@  \n'
      statData += `Last updated on _${new Date().toUTCString()}_\n`

      statData += '### Total problems solved:\n'
      statData += '| Accepted | Partially accepted |\n'
      statData += '| --- | --- |\n'
      statData += `| ${totalProblemCount.accepted} | ${totalProblemCount.unaccepted} |\n`

      statData += '### Total problems solved per language:\n'
      statData += '| Language  | Accepted | Partially accepted |\n'
      statData += '| --- | --- | --- |\n'

      for(language in totalLanguageCounter){
        const acceptedCount = totalLanguageCounter[language].accepted
        const unacceptedCount = totalLanguageCounter[language].unaccepted ?? 0

        statData += `| ${getFullLanguageName(language)} | ${acceptedCount} | ${unacceptedCount} |\n`
      }

      statData += '---\n' 
      
      statData += '![pie-chart-1](./stats/generated/pie-chart-1.PNG)\n'
      statData += '![pie-chart-2](./stats/generated/pie-chart-2.PNG)\n'
      statData += '![bar-chart](./stats/generated/bar-chart.PNG)\n'

      statData += '---\n'

      await appendFile(filePath, statData)
      
      resolve()
    }catch(err){
      console.log(err)
      reject()
    }
  })
}

async function generateStats() {
  try{
    const startTime = Date.now()
    console.log(`Solutions Stat Generation Started at: ${new Date().toISOString()}`)

    const statsMap = await generateStatsMap()

    const statsArr = convertMapToArray(statsMap)

    const {totalProblemCount, totalLanguageCounter, fileCounter} = generateTotalProblemCounter(statsArr)
    console.log(totalProblemCount)
    console.log(totalLanguageCounter)
    console.log(fileCounter)

    console.log(statsArr.filter(({quesId}) => quesId === 25)[0])
    console.log(statsArr.filter(({quesId}) => quesId === 233)[0])

    await generateJSFile(statsArr)

    await generateCSVFile(statsArr)

    await updateStatsinReadmeFile(totalProblemCount, totalLanguageCounter)

    console.log(`Solutions Stat Generation Completed at: ${new Date().toISOString()}`)
    const endTime = Date.now()
    console.log(`Time Taken to Generate Solution stats = ${endTime - startTime} ms`)

  }catch(err){
    console.log(err)
  }
}

generateStats()