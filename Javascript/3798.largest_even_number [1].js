/**
 * @param {string} s
 * @return {string}
 */
var largestEven = function(s) {
    let idx = -1
    for(let i=s.length-1; i>=0; i--){
        if(s[i] === '2'){
            idx = i
            break
        }
    }

    return s.substring(0, idx + 1)
};