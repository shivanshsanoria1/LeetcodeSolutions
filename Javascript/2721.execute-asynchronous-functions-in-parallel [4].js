/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = async function(functions) {
    const promises = functions.map((fn) => fn());
    return new Promise((resolve, reject) => {
        const ans = [];
        let promisesLeft = promises.length;
        promises.forEach((promise, index) => {
            Promise.resolve(promise)
            .then((result) => {
                ans[index] = result;
                promisesLeft--;
                if(promisesLeft === 0)
                    resolve(ans);
            })
            .catch((err) => {
                reject(err);
            });
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */