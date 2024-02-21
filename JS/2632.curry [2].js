/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    const argsAll = [];
    return function curried(...args) {
        argsAll.push(...args);
        if(fn.length === argsAll.length)
            return fn(...argsAll);
        else
            return curried;
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
