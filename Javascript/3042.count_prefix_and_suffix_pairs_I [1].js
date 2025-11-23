// returns true if s1 is both a prefix and suffix of s2
function isPrefixAndSuffix(s1, s2){
    const n1 = s1.length, n2 = s2.length

    if(n1 > n2)
        return false

    return s2.substring(0, n1) === s1 && s2.substring(n2-n1) === s1
}


/**
 * @param {string[]} words
 * @return {number}
 */
var countPrefixSuffixPairs = function(words) {
    const n = words.length
    let count = 0

    for(let i=0; i<n-1; i++)
        for(let j=i+1; j<n; j++)
            if(isPrefixAndSuffix(words[i], words[j]))
                count++
    
    return count
};