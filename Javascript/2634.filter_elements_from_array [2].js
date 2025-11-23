/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let i=-1;
    return arr.filter((ele) => {
        i++;
        return fn(ele, i);
    });
};