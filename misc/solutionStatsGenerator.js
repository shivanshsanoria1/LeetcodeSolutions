const path = require('node:path');
const { readdir, writeFile } = require('node:fs/promises');

function readSolutionStats(){
  return new Promise(async(resolve, reject) => {
    try{
      const dirPath_cpp_1_500 = path.join(__dirname, '..', 'CPP [1-500]')
      const dirPath_cpp_501_1000 = path.join(__dirname, '..', 'CPP [501-1000]')
      const dirPath_cpp_1001_1500 = path.join(__dirname, '..', 'CPP [1001-1500]')
      const dirPath_cpp_1501_2000 = path.join(__dirname, '..', 'CPP [1501-2000]')
      const dirPath_cpp_2001_2500 = path.join(__dirname, '..', 'CPP [2001-2500]')
      const dirPath_cpp_2501_3000 = path.join(__dirname, '..', 'CPP [2501-3000]')
      const dirPath_cpp_3001_3500 = path.join(__dirname, '..', 'CPP [3001-3500]')
      const dirPath_js = path.join(__dirname, '..', 'JS')
      const dirPath_sql = path.join(__dirname, '..', 'SQL')
      
      const dirPaths = [
        dirPath_cpp_1_500,
        dirPath_cpp_501_1000,
        dirPath_cpp_1001_1500,
        dirPath_cpp_1501_2000,
        dirPath_cpp_2001_2500,
        dirPath_cpp_2501_3000,
        dirPath_cpp_3001_3500,
        dirPath_js, 
        dirPath_sql
      ]

      const solutionsStatMap = new Map()

      for(const dirPath of dirPaths){
        const fileNames = await readdir(dirPath)
  
        for(const fileName of fileNames){
          const filePath = path.join(dirPath, fileName)
  
          const quesId = parseInt(fileName.split('.')[0])
          const title = fileName.split('.')[1].split(' ')[0].split('_').join(' ')
          const language = path.extname(filePath).substring(1).toLowerCase()
          const isAccepted = fileName.search('TLE') === -1 && fileName.search('MLE') === -1
          
          let solutionstats = null 
          
          if(!solutionsStatMap.has(quesId)){
            solutionstats = {
              quesId,
              title,
              languages: {
                cpp: {
                  acceptedCount: language === 'cpp' && isAccepted ? 1 : 0, 
                  unacceptedCount: language === 'cpp' && !isAccepted ? 1 : 0, 
                },
                js: {
                  acceptedCount: language === 'js' && isAccepted ? 1 : 0, 
                  unacceptedCount: language === 'js' && !isAccepted ? 1 : 0, 
                },
                sql: {
                  acceptedCount: language === 'sql' && isAccepted ? 1 : 0, 
                  unacceptedCount: language === 'sql' && !isAccepted ? 1 : 0, 
                },
              },
            }

          } else{
            solutionstats = solutionsStatMap.get(quesId)

            if(language === 'cpp'){
              if(isAccepted)
                solutionstats.languages.cpp.acceptedCount++
              else
                solutionstats.languages.cpp.unacceptedCount++

            } else if(language === 'js'){
              if(isAccepted)
                solutionstats.languages.js.acceptedCount++
              else
                solutionstats.languages.js.unacceptedCount++

            } else if(language === 'sql'){
              if(isAccepted)
                solutionstats.languages.sql.acceptedCount++
              else
                solutionstats.languages.sql.unacceptedCount++
            }
          }

          solutionsStatMap.set(quesId, solutionstats)
        }
      }
      
      resolve(solutionsStatMap)

    }catch(err){
      console.log(err)
      reject()
    }
  })
}

function convertMapToArray(mp){
  const arr = []
  for(const [quesId, obj] of mp){
    const {quesId, title, languages} = obj

    const languagesArr = []
    const acceptedCountArr = []
    const unacceptedCountArr = []

    if(languages.cpp.acceptedCount > 0 || languages.cpp.unacceptedCount > 0){
      languagesArr.push('cpp')
      acceptedCountArr.push(languages.cpp.acceptedCount.toString())
      unacceptedCountArr.push(languages.cpp.unacceptedCount.toString())
    }

    if(languages.js.acceptedCount > 0 || languages.js.unacceptedCount > 0){
      languagesArr.push('js')
      acceptedCountArr.push(languages.js.acceptedCount.toString())
      unacceptedCountArr.push(languages.js.unacceptedCount.toString())
    }

    if(languages.sql.acceptedCount > 0 || languages.sql.unacceptedCount > 0){
      languagesArr.push('sql')
      acceptedCountArr.push(languages.sql.acceptedCount.toString())
      unacceptedCountArr.push(languages.sql.unacceptedCount.toString())
    }

    arr.push({
      quesId,
      title,
      languages: languagesArr.join('+'),
      acceptedCount: acceptedCountArr.join('+'),
      unacceptedCount: unacceptedCountArr.join('+')
    })
  }

  return arr.sort((a, b) => a.quesId - b.quesId)
}

function writeSolutionStatsToCSV(solutionsStatArray) {
  return new Promise(async(resolve, reject) => {
    try{
      let solutionsStatsStringified = 'quesId,Title,Language(s),AcceptedCount,UnacceptedCount\n'

      for(const solutionStats of solutionsStatArray){
        const {
          quesId, 
          title, 
          languages, 
          acceptedCount, 
          unacceptedCount
        } = solutionStats

        const titleWithOutCommas = title.replace(/,/g, '*')
        
        solutionsStatsStringified += `${quesId},${titleWithOutCommas},${languages},${acceptedCount},${unacceptedCount}\n`
      }
      
      const dateTime = new Date().toISOString().split(':').join('-').split('.').join('-')
      const csvFilePath = path.join(__dirname, 'stats', `solution_stats_metadata [${dateTime}].csv`)
      await writeFile(csvFilePath, solutionsStatsStringified)

      resolve()

    }catch(err){
      console.log(err)
      reject()
    }
  })
}

async function generateSolutionStats() {
  try{
    const startTime = Date.now()
    console.log(`Solutions Stat Generation Started at: ${new Date().toISOString()}`)

    const solutionsStatMap = await readSolutionStats()

    const solutionsStatArray = convertMapToArray(solutionsStatMap)

    await writeSolutionStatsToCSV(solutionsStatArray)

    console.log(`Solutions Stat Generation Completed at: ${new Date().toISOString()}`)
    const endTime = Date.now()
    console.log(`Time Taken to Generate Solution stats = ${endTime - startTime} ms`)

  }catch(err){
    console.log(err)
  }
}

generateSolutionStats()