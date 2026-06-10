/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    const chunkedArr = [];
    let chunk = [];
    for(const ele of arr){
        chunk.push(ele);
        if(chunk.length === size){ // chunk reached its capacity
            chunkedArr.push(chunk);
            chunk = []; // clear the chunk
        }
    }
    if(chunk.length > 0){ // last chunk is left
        chunkedArr.push(chunk);
    }
    return chunkedArr;
};