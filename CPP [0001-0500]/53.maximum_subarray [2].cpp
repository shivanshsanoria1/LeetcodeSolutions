class Solution {
public:
    int maxSubArray(vector<int>& nums) { // DP, T.C.=O(n), S.C.=O(n)
        int n=nums.size(); 
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<n; i++)
        {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};