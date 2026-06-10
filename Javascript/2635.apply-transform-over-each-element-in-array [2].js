/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let i=-1;
    return arr.map((ele) => {
        i++;
        return fn(ele, i);
    });
};