Array.prototype.custom_map = function(cb){
    const mappedArr = []
    for(const x of this){
        mappedArr.push(cb(x))
    }
    
    return mappedArr
}

Array.prototype.custom_filter = function(cb){
    const filteredArr = []
    for(const x of this){
        if(cb(x)){
            filteredArr.push(x)
        }
    }
    
    return filteredArr
}

Array.prototype.custom_reduce = function(cb, acc){
    let reducedValue = acc
    for(const x of this){
        reducedValue = cb(reducedValue, x)
    }
    
    return reducedValue
}

const arr = [2, -4, 6, 0, 3, -1, 5]
console.log('Original Array: ')
console.log(arr)

// const arr1 = arr.map((x) => x*x)
const arr1 = arr.custom_map((x) => x*x)
console.log('\nMapped Array: ')
console.log(arr1)

// const arr2 = arr.filter((x) => x % 2 === 0)
const arr2 = arr.custom_filter((x) => x % 2 === 0)
console.log('\nFiltered Array: ')
console.log(arr2)

// const val3 = arr.reduce((acc, x) => acc + x, 0)
const val3 = arr.custom_reduce((acc, x) => acc + x, 0)
console.log('\nReduced Value: ')
console.log(val3)

console.log('\n----------------------------')