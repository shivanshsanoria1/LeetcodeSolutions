class Solution {
private:
    int solve(vector<int>& nums, int tar, vector<int>& dp){
        if(tar < 0)
            return 0;

        if(dp[tar] != -1)
            return dp[tar];

        int sum = 0;
        for(int num: nums)
            sum += solve(nums, tar - num, dp);

        dp[tar] = sum;
        return dp[tar];
    }

public:
    // DP: Memoization
    int combinationSum4(vector<int>& nums, int target) { 
        vector<int> dp(target + 1, -1);
        dp[0] = 1;

        return solve(nums, target, dp);
    }
};

// dp[i]: number of ways to sum upto the target i using the numbers from nums[]  