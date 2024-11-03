/**
 * @param {string} num
 * @return {boolean}
 */
var isBalanced = function(num) {
    let sum0 = 0, sum1 = 0
    for(let i=0; i<num.length; i++){
        if(i % 2 === 0)
            sum0 += Number(num[i])
        else
            sum1 += Number(num[i])
    }

    return sum0 === sum1
};