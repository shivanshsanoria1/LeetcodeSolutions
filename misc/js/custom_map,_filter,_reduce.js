Array.prototype.customMap = function(cb){
    const mappedArr = []
    for(const x of this){
        mappedArr.push(cb(x))
    }
    
    return mappedArr
}

Array.prototype.customFilter = function(cb){
    const filteredArr = []
    for(const x of this){
        if(cb(x)){
            filteredArr.push(x)
        }
    }
    
    return filteredArr
}

Array.prototype.customReduce = function(cb, acc){
    let reducedValue = acc
    for(const x of this){
        reducedValue = cb(reducedValue, x)
    }
    
    return reducedValue
}

const arr = [2, -4, 6, 0, 3, -1, 5]
console.log('Original Array: ')
console.log(arr)

const arr1 = arr.customMap((x) => x*x)
console.log('\nMapped Array: ')
console.log(arr1)

const arr2 = arr.customFilter((x) => x % 2 === 0)
console.log('\nFiltered Array: ')
console.log(arr2)

const arr3 = arr.customReduce((acc, x) => acc + x, 0)
console.log('\nReduced Value: ')
console.log(arr3)

console.log('\n----------------------------')