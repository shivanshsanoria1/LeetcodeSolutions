// returns The index of the first element that passes a test 
// (and -1 if not found)
Array.prototype.custom_findIndex = function(cb){
    for(let i=0; i<this.length; i++){
        if(cb(this[i])){
            return i
        }
    }
    
    return -1
}

// returns The index of the last element that passes a test
// (and -1 if not found)
Array.prototype.custom_findLastIndex = function(cb){
    for(let i=this.length-1; i>=0; i--){
        if(cb(this[i])){
            return i
        }
    }
    
    return -1
}

// returns The value of the first element that passes a test
// (and undefined if not found)
Array.prototype.custom_find = function(cb){
    for(const x of this){
        if(cb(x)){
            return x
        }
    }
    
    return undefined
}

// returns The value of the last element that passes a test
// (and undefined if not found)
Array.prototype.custom_findLast = function(cb){
    for(let i=this.length-1; i>=0; i--){
        if(cb(this[i])){
            return this[i]
        }
    }
    
    return undefined
}

const arr = [1, 2, 3, -2, 7, 0, -3, 10, 16]

// console.log(arr.findIndex((x) => x < 0))
// console.log(arr.findIndex((x) => x < -20))
console.log(arr.custom_findIndex((x) => x < 0))
console.log(arr.custom_findIndex((x) => x < -20))
console.log('--------------------\n')

// console.log(arr.findLastIndex((x) => x < 0))
// console.log(arr.findLastIndex((x) => x < -20))
console.log(arr.custom_findLastIndex((x) => x < 0))
console.log(arr.custom_findLastIndex((x) => x < -20))
console.log('--------------------\n')

// console.log(arr.find((x) => x < 0))
// console.log(arr.find((x) => x < -20))
console.log(arr.custom_find((x) => x < 0))
console.log(arr.custom_find((x) => x < -20))
console.log('--------------------\n')

// console.log(arr.findLast((x) => x < 0))
// console.log(arr.findLast((x) => x < -20))
console.log(arr.custom_findLast((x) => x < 0))
console.log(arr.custom_findLast((x) => x < -20))
console.log('--------------------\n')
