/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reversePrefix = function(s, k) {
    const str1 = s.slice(0, k).split('').reverse().join('')
    const str2 = s.slice(k)

    return str1 + str2
};