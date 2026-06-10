/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    const chunkedArr = [];
    let i = 0;
    while(i < arr.length){
        chunkedArr.push(arr.slice(i, i+size));
        i += size;
    }
    return chunkedArr;
};
