/**
 * @param {string[]} words
 * @param {string} pref
 * @return {number}
 */
var prefixCount = function(words, pref) {
    return words.reduce((acc, word) => acc + (word.substring(0, pref.length) === pref ? 1 : 0), 0)
};