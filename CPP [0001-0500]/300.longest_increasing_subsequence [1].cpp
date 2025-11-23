class Solution {
private:
    int lis(vector<int>& nums, int i, int prevIdx, vector<vector<int>>& dp){
        if(i >= nums.size())
            return 0;
        
        if(dp[i][prevIdx + 1] != -1)
            return dp[i][prevIdx + 1];

        int exclude = lis(nums, i+1, prevIdx, dp);
        int include = prevIdx == -1 || nums[i] > nums[prevIdx] ? 1 + lis(nums, i+1, i, dp) : 0;

        dp[i][prevIdx + 1] = max(exclude, include);
        return dp[i][prevIdx + 1]; 
    }

public:
    // T.C.=O(n^2), S.C.=O(n^2)
    // DP: Memoization
    int lengthOfLIS(vector<int>& nums) { 
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return lis(nums, 0, -1, dp);
    }
};