class Solution {
private:
    int solve(vector<int>& nums, int k, int prevIdx, int currIdx, vector<vector<int>>& dp){
        int n=nums.size();
        if(currIdx == n)
            return 0;

        if(dp[prevIdx + 1][currIdx] != -1)
            dp[prevIdx + 1][currIdx];

        int res = 0;
        for(int i=currIdx; i<n; i++)
        {
            // excluding the element at index i 
            res = max(res, solve(nums, k, prevIdx, i+1, dp));
            // including the element at index i 
            if(prevIdx == -1 || (nums[i] > nums[prevIdx] && nums[i] - nums[prevIdx] <= k))
                res = max(res, 1 + solve(nums, k, i, i+1, dp));
        }

        dp[prevIdx + 1][currIdx] = res;
        return dp[prevIdx + 1][currIdx]; 
    }

public:
    // T.C.=O(n^2), S.C.=O(n^2)
    // DP: Memoization
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n, -1));

        return solve(nums, k, -1, 0, dp);
    }
};