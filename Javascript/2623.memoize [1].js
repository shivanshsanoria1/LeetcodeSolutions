/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    // arguments-hash -> fn(arguments)
    const mp = new Map();

    return function(...args) {
        const hash = args.join('#')

        if(!mp.has(hash))
            mp.set(hash, fn(...args))

        return mp.get(hash)
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *   callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */