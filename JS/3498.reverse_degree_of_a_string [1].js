/**
 * @param {string} s
 * @return {number}
 */
var reverseDegree = function(s) {
    let sum = 0
    for(let i=0; i<s.length; i++)
        sum += (26 - (s.charCodeAt(i) - 'a'.charCodeAt(0))) * (i+1)
    
    return sum
};