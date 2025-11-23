/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumMedianSum = function(nums) {
    nums.sort((a, b) => a-b)

    let sum = 0
    for(let i=0, j=nums.length-1; i<j; i++, j-=2)
        sum += nums[j-1]

    return sum
};