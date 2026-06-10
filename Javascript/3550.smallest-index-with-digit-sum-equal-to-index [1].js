/**
 * @param {number[]} nums
 * @return {number}
 */
var smallestIndex = function(nums) {
    function digitSum(num){
        const str = String(num)
        
        let sum = 0
        for(const ch of str)
            sum += ch - '0'

        return sum
    }

    for(let i=0; i<nums.length; i++)
        if(digitSum(nums[i]) === i)
            return i
    
    return -1
};