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
      const dirPath_mysql = path.join(__dirname, '..', 'MYSQL')
      
      const dirPaths = [
        dirPath_cpp_1_500,
        dirPath_cpp_501_1000,
        dirPath_cpp_1001_1500,
        dirPath_cpp_1501_2000,
        dirPath_cpp_2001_2500,
        dirPath_cpp_2501_3000,
        dirPath_cpp_3001_3500,
        dirPath_js, 
        dirPath_mysql
      ]

      const solutionsStatMap = new Map()

      const fileCount = { cpp: 0, js: 0, mysql: 0 }

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
                mysql: {
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
                solutionstats.languages.mysql.acceptedCount++
              else
                solutionstats.languages.mysql.unacceptedCount++
            }
          }

          solutionsStatMap.set(quesId, solutionstats)

          if(language === 'cpp')
            fileCount.cpp++
          else if(language === 'js')
            fileCount.js++
          else if(language === 'sql')
            fileCount.mysql++
        }
      }
      
      // console.log(`Total files = ${fileCount.cpp} in cpp, ${fileCount.js} in js, ${fileCount.mysql} in mysql`)

      resolve({solutionsStatMap, fileCount})

    }catch(err){
      console.log(err)
      reject()
    }
  })
}

function convertMapToArray(mp){
  const arr = []

  const solutionCount = {
    cpp: {accepted: 0, unaccepted: 0},
    js: {accepted: 0, unaccepted: 0},
    mysql: {accepted: 0, unaccepted: 0},
    totalAccepted: 0,
    totalUnaccepted: 0,
  }

  for(const [quesId, obj] of mp){
    const {quesId, title, languages} = obj

    const languagesArr = []
    const acceptedCountArr = []
    const unacceptedCountArr = []

    if(languages.cpp.acceptedCount > 0 || languages.cpp.unacceptedCount > 0){
      languagesArr.push('cpp')
      acceptedCountArr.push(languages.cpp.acceptedCount.toString())
      unacceptedCountArr.push(languages.cpp.unacceptedCount.toString())

      if(languages.cpp.acceptedCount > 0)
        solutionCount.cpp.accepted++
      else
        solutionCount.cpp.unaccepted++
    }

    if(languages.js.acceptedCount > 0 || languages.js.unacceptedCount > 0){
      languagesArr.push('js')
      acceptedCountArr.push(languages.js.acceptedCount.toString())
      unacceptedCountArr.push(languages.js.unacceptedCount.toString())
      
      if(languages.js.acceptedCount > 0)
        solutionCount.js.accepted++
      else
        solutionCount.js.unaccepted++
      
    }

    if(languages.mysql.acceptedCount > 0 || languages.mysql.unacceptedCount > 0){
      languagesArr.push('mysql')
      acceptedCountArr.push(languages.mysql.acceptedCount.toString())
      unacceptedCountArr.push(languages.mysql.unacceptedCount.toString())
      
      if(languages.mysql.acceptedCount > 0)
        solutionCount.mysql.accepted++
      else
        solutionCount.mysql.unaccepted++
    }

    if(languages.cpp.acceptedCount > 0 || languages.js.acceptedCount > 0 || languages.mysql.acceptedCount > 0)
      solutionCount.totalAccepted++
    else
      solutionCount.totalUnaccepted++

    arr.push({
      quesId,
      title,
      languages: languagesArr.join('+'),
      acceptedCount: acceptedCountArr.join('+'),
      unacceptedCount: unacceptedCountArr.join('+')
    })
  }

  arr.sort((a, b) => a.quesId - b.quesId)

  // console.log('--------------------')
  // console.log('Solution Count for each language: ')
  // console.log(`CPP: accepted = ${solutionCount.cpp.accepted}, unaccepted = ${solutionCount.cpp.unaccepted}`)
  // console.log(`JS: accepted = ${solutionCount.js.accepted}, unaccepted = ${solutionCount.js.unaccepted}`)
  // console.log(`MYSQL: accepted = ${solutionCount.mysql.accepted}, unaccepted = ${solutionCount.mysql.unaccepted}`)
  // console.log(`Total Accepted = ${solutionCount.totalAccepted}`)
  // console.log(`Total Unaccepted = ${solutionCount.totalUnaccepted}`)
  // console.log('--------------------')

  // console.table(arr.filter(({languages}) => languages.includes('js')))

  return {
    solutionsStatArray: arr, 
    solutionCount
  }
}

function writeSolutionStatsToFiles(solutionsStatArray, fileCount, solutionCount) {
  return new Promise(async(resolve, reject) => {
    try{
      let solutionsStatsStringified = 'quesId,Title,Language(s),AcceptedCount,UnacceptedCount\n'
      let solutionsStatArrayStringified = '[\n'

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

        solutionsStatArrayStringified += '  ' + JSON.stringify(solutionStats) + ', \n'
      }

      solutionsStatArrayStringified += ']'

      const solutionsStatTotalStringified = 
      `Solution count per language: \n` + 
      `Language | Accepted | Unaccepted |\n` + 
      `   cpp   |   ${solutionCount.cpp.accepted.toString().padStart(4, ' ')}   |   ${solutionCount.cpp.unaccepted.toString().padStart(4, ' ')}     |\n` + 
      `   js    |   ${solutionCount.js.accepted.toString().padStart(4, ' ')}   |   ${solutionCount.js.unaccepted.toString().padStart(4, ' ')}     |\n` + 
      `  mysql  |   ${solutionCount.mysql.accepted.toString().padStart(4, ' ')}   |   ${solutionCount.mysql.unaccepted.toString().padStart(4, ' ')}     |\n` + 
      `----------------------------------\n\n` + 
      `Total Solutions: \n` + 
      `Accepted = ${solutionCount.totalAccepted}\n` +
      `Unaccepted = ${solutionCount.totalUnaccepted}\n` + 
      `----------------------------------\n\n` + 
      `Total files: \n` + 
      `cpp = ${fileCount.cpp} \n` + 
      `js = ${fileCount.js } \n` + 
      `mysql = ${fileCount.mysql} \n` + 
      `----------------------------------\n\n`

      const dateTime = new Date().toISOString().split(':').join('-').split('.').join('-')

      const csvFilePath = path.join(__dirname, 'generated', `solution_stats [${dateTime}].csv`)
      await writeFile(csvFilePath, solutionsStatsStringified)

      const txtFilePath = path.join(__dirname, 'generated', `solution_stats_total [${dateTime}].txt`)
      await writeFile(txtFilePath, solutionsStatTotalStringified)

      const jsFilePath = path.join(__dirname, 'generated', `solution_stats_array [${dateTime}].js`)
      await writeFile(jsFilePath, solutionsStatArrayStringified)

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

    const {solutionsStatMap, fileCount} = await readSolutionStats()

    const {solutionsStatArray, solutionCount} = convertMapToArray(solutionsStatMap)

    await writeSolutionStatsToFiles(solutionsStatArray, fileCount, solutionCount)

    console.log(`Solutions Stat Generation Completed at: ${new Date().toISOString()}`)
    const endTime = Date.now()
    console.log(`Time Taken to Generate Solution stats = ${endTime - startTime} ms`)

  }catch(err){
    console.log(err)
  }
}

generateSolutionStats()