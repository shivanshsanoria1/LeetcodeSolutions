/**
 * @param {string} s
 * @return {number}
 */
var minChanges = function(s) {
    let ops = 0 // operations
    for(let i=0; i<s.length; i += 2)
        if(s[i] !== s[i+1])
            ops++

    return ops
};