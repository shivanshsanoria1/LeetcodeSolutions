/**
 * @param {string} s
 * @return {string}
 */
var trimTrailingVowels = function(s) {
    function isVowel(ch){
        return ch === 'a' || ch === 'e' || ch === 'i' || ch === 'o' || ch === 'u'
    }

    const chars = s.split('')
    
    for(let i=chars.length-1; i>=0; i--){
        if(isVowel(chars[i]))
            chars.pop()
        else
            break
    }

    return chars.join('')
};