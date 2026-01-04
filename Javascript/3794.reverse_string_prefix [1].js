/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reversePrefix = function(s, k) {
    const str1 = s.split('').slice(0, k).reverse().join('')
    const str2 = s.split('').slice(k).join('')

    return str1 + str2
};