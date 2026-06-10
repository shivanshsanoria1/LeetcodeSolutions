/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    function findVowelCount(s){
        const vowels = ['a', 'e', 'i', 'o', 'u']

        return s.split('').reduce((acc, ch) => acc + vowels.includes(ch), 0)
    }

    const words = s.split(' ')
    const vowelCount1 = findVowelCount(words[0])
    let ans = words[0]

    for(let i=1; i<words.length; i++){
        ans += ' '
        
        if(findVowelCount(words[i]) === vowelCount1){
            ans += words[i].split('').reverse().join('')
        }else{
            ans += words[i]
        }
    }

    return ans
};