/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    while(true){
        const digitSum = num
        .toString()
        .split('')
        .reduce((acc, dig) => acc + parseInt(dig), 0)

        if(digitSum < 10)
            return digitSum
        
        num = digitSum
    }

    return -1
};