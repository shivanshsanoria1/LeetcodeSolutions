/**
 * @param {string} s
 * @return {string}
 */
var makeFancyString = function(s) {
        let len = 1
        let ans = ''
        ans += s[0]

        for(let i=1; i<s.length; i++){
            if(s[i-1] === s[i])
                len++
            else
                len = 1
                
            if(len < 3)
                ans += s[i]
        }

        return ans
};