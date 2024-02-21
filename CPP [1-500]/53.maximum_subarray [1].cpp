class Solution {
public:
    int maxSubArray(vector<int>& nums) { // Kadane's algo., T.C.=O(n), S.C.=O(1)
        int maxSum = nums[0];
        int currSum = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            currSum = max(nums[i], nums[i] + currSum);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};