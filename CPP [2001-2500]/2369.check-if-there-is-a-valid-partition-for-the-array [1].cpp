class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& dp, int i){
        int n=nums.size();
        if(i == n)
            return true;

        if(dp[i] != -1)
            return dp[i];

        bool cond1 = i+1 < n && nums[i] == nums[i+1];
        if(cond1 && solve(nums, dp, i+2))
        {
            dp[i] = 1;
            return dp[i];
        }

        bool cond2 = i+2 < n && nums[i] == nums[i+1] && nums[i] == nums[i+2];
        bool cond3 = i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1;
        if((cond2 || cond3) && solve(nums, dp, i+3))
        {
            dp[i] = 1;
            return dp[i];
        }

        dp[i] = 0;
        return dp[i];
    }

    bool validPartition(vector<int>& nums) { // Memoization, T.C.=O(n), S.C.=O(n)
        int n=nums.size();
        vector<int> dp(n, -1);
        return solve(nums, dp, 0);
    }
};