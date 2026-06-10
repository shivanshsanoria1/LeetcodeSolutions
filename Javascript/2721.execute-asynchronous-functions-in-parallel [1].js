/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {
    try{
        const promises = functions.map((fn) => fn());
        const ans = await Promise.all(promises);
        return ans;
    }catch(err){
        throw err;
    }
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */