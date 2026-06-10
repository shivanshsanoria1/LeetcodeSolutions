/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {
    const promises = functions.map((fn) => fn());
    return new Promise((resolve, reject) => {
        const ans = [];
        let promisesLeft = promises.length;
        for(let i=0; i<promises.length; i++){
            Promise.resolve(promises[i])
            .then((result) => {
                ans[i] = result;
                promisesLeft--;
                if(promisesLeft === 0)
                    resolve(ans);
            })
            .catch((err) => {
                reject(err);
            });
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */