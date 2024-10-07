/**
 * @param {string} s
 * @return {number}
 */
var minLength = function(s) {
    let curr = s

    while(curr.includes('AB') || curr.includes('CD')){
        curr = curr.replace(/AB/g, '').replace(/CD/g, '')
    }

    return curr.length
};