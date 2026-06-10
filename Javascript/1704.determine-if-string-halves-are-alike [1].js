/**
 * @param {string} s
 * @return {boolean}
 */
var halvesAreAlike = function(s) {
    function isVowel(ch){
        ch = ch.toLowerCase()
        return ch === 'a' || ch === 'e' || ch === 'i' || ch === 'o' || ch === 'u'
    }

    const n = s.length

    let leftVowelCount = 0;
    for(let i=0; i<n/2; i++)
        if(isVowel(s[i]))
            leftVowelCount++
    
    let rightVowelCount = 0;
    for(let i=n/2; i<n; i++)
        if(isVowel(s[i]))
            rightVowelCount++

    return leftVowelCount === rightVowelCount
};