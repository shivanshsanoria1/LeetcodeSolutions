// generates a random number in range [start, end]
function generateRandomNumber(start, end){
    return start + Math.floor(Math.random() * (end - start + 1))
}

function convertMapToArray(mp){
    const arr = []
    for(const [num, freq] of mp){
        arr.push({num, freq})
    }
    
    arr.sort((a, b) => a.num - b.num)
    
    return arr
}

let count = 518
const start = 1
const end = 50

const avgFreq = count / (end - start + 1)

// number -> frequency
const mp = new Map()

console.log(`Generating ${count} random numbers in range [${start}, ${end}]...\n`)

while(count-- > 0){
    const randNum = generateRandomNumber(start, end)
    
    if(mp.has(randNum)){
        mp.set(randNum, mp.get(randNum) + 1)
    }else{
        mp.set(randNum, 1)
    }
}

const arr = convertMapToArray(mp)

console.log("Number -> Frequency")
let minFreq = 2**31 - 1
let maxFreq = 0

for(const {num, freq} of arr){
    console.log(num + " -> " + freq)
    
    minFreq = Math.min(minFreq, freq)
    maxFreq = Math.max(maxFreq, freq)
}

console.log('\nMin freq = ' + minFreq)
console.log('Max freq = ' + maxFreq)
console.log('Avg freq expected = ' + avgFreq)

console.log('-----------------------------')