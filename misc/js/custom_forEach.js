Array.prototype.custom_forEach = function(cb){
    for(const x of this){
        cb(x)
    }
}

const arr = [1, 2, 3, -2, 7, 0, -3, 10, 16]

// arr.forEach((x) => console.log(x))
arr.custom_forEach((x) => console.log(x))
console.log('--------------------\n')
