function generateRandomAlphaNumericString(len = 13){
    const chars = []

    // uppercase-alphabets: A-Z
    for(let i=0; i<26; i++){
        chars.push(String.fromCharCode(65 + i))
    }

    // digits: 0-9
    for(let i=0; i<=9; i++){
        chars.push(String.fromCharCode(48 + i))
    }

    // lowercase-alphabets: a-z
    for(let i=0; i<26; i++){
        chars.push(String.fromCharCode(97 + i))
    }

    let randStr = ''
    while(len-- > 0){
        const randIdx = Math.floor(Math.random() * chars.length)
        randStr += chars[randIdx]
    }

    return randStr
}

// number of strings to be generated
let count = 100
// length of each string (default is 13)
const len = 13

console.log(`Generating ${count} alpha-numeric strings of length ${len} ...\n`)

for(let i=1; i<=count; i++){
    console.log(i + ' -> ' + generateRandomAlphaNumericString(len))
}

console.log('\n--------------------------------')