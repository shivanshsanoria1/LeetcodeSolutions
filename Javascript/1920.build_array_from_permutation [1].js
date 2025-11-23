/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function(nums) {
    const ans = []
    for(const num of nums)
        ans.push(nums[num])
    
    return ans
};