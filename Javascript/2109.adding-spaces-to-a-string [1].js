/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function(s, spaces) {
    let ans = s.substring(0, spaces[0])

    for(let i=1; i<spaces.length; i++){
        ans += ' ' + s.substring(spaces[i-1], spaces[i])
    }

    ans += ' ' + s.substring(spaces[spaces.length - 1])

    return ans
};