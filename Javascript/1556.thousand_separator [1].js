/**
 * @param {number} n
 * @return {string}
 */
var thousandSeparator = function(n) {
    const revDigits = n.toString().split('').reverse()
    const digits = []
    let count = 0;

    for(const digit of revDigits){
        digits.push(digit)
        
        if(++count == 3){
            count = 0
            digits.push('.')
        }
    }

    if(digits[digits.length - 1] === '.')
        digits.pop()

    return digits.reverse().join('')
};