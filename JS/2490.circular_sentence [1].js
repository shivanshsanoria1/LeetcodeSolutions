/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function(sentence) {
    if(sentence[0] !== sentence.at(-1))
        return false

    const words = sentence.split(' ')

    for(let i=1; i<words.length; i++)
        if(words[i-1].at(-1) !== words[i][0])
            return false

    return true
};