// returns a new array in index-range [start, end) of the original array
Array.prototype.custom_slice = function(start = 0, end = this.length){
    if(start < 0 || start >= this.length){
        throw new Error('Invalid start-index!')
    }
    
    if(end <= 0 || end > this.length){
        throw new Error('Invalid end-index!')
    }
    
    if(start >= end){
        throw new Error('Invalid start-index must be less than end-index!')
    }
    
    const sliced = []
    for(let i=start; i<end; i++){
    	sliced.push(this[i])
    }
    
    return sliced
}

const arr = [5, 10, 20, 30, 40, 50, 60]

try{
    console.log(arr.custom_slice(1, 4))
    console.log(arr.custom_slice(2))
    console.log(arr.custom_slice())
    // console.log(arr.custom_slice(-1))
    // console.log(arr.custom_slice(1, 12))
    // console.log(arr.custom_slice(4, 4))
    
}catch(err){
    console.log(err)
}