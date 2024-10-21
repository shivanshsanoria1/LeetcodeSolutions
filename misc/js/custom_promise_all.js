/*
# custom Promise.all()
# takes an array of promises as argument
# returns a promise which resolves with an array of values resolved by each promise
# throws an error if any of the promise rejects
*/
function customPromiseAll(promises){
    return new Promise((resolve, reject) => {
        const arr = []
        let promisesLeft = promises.length
        
        promises.forEach((promise, index) => {
            Promise.resolve(promise)
            .then((result) => {
                arr[index] = result
                if(--promisesLeft === 0)
                    resolve(arr)
            })
            .catch((err) => {
                reject(err)
            })
        })
    })
}

// IIFE
(async function(){
    const p1 = new Promise((resolve, reject) => {
        setTimeout(() => resolve(1), 3000)
    })
    
    const p2 = new Promise((resolve, reject) => {
        setTimeout(() => resolve(2), 2000)
    })
    
    const p3 = new Promise((resolve, reject) => {
        setTimeout(() => resolve(3), 1000)
    })
    
    const promises = [p1, p2, p3]
    
    const startTime = Date.now()
    try{
        // using inbuilt Promise.all()
        // const p = await Promise.all(promises)
        
        // using custom Promise.all()
        const p = await customPromiseAll(promises)
        
        console.log(p)
        console.log(`Time taken = ${Date.now() - startTime} ms`)
        
    }catch(err){
        console.log(err)
        console.log(`Time taken = ${Date.now() - startTime} ms`)
    }
    
})()