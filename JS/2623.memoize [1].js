/**
 * @param {Function} fn
 */
function memoize(fn) {
    const mp = new Map(); // [...args] -> fn(...args)
    return function(...args) {
        const stringifiedArgs = [...args].toString(); // convert array of args to string
        if(mp.has(stringifiedArgs)) // no need to call fn, result already in map
            return mp.get(stringifiedArgs);
        const result = fn(...args);
        mp.set(stringifiedArgs, result); // add args and result in map
        return result;
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