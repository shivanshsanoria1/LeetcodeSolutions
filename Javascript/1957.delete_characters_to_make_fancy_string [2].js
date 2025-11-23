/**
 * @param {string} s
 * @return {string}
 */
var makeFancyString = function(s) {
        let prev2 = '#'
        let prev1 = '#'
        let ans = ''

        for(const ch of s){
            if(prev1 === '#'){
                prev1 = ch
                ans += ch
            }
            else if(prev2 === '#' || prev1 !== ch || prev2 !== ch){
                prev2 = prev1
                prev1 = ch
                ans += ch
            }
        }

        return ans
};