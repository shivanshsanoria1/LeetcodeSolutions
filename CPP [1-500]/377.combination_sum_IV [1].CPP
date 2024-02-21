class Solution {
public:
    int solve(vector<int>& dp, vector<int>& nums, int tar){
        if(tar < 0)
            return 0;
        if(dp[tar] != -1) // solution found in dp
            return dp[tar];
        int sum = 0;
        for(int num: nums)
            sum += solve(dp, nums, tar - num);
        dp[tar] = sum; // store the curr solution in dp
        return dp[tar];
    }

    int combinationSum4(vector<int>& nums, int target) { // Memoization
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return solve(dp, nums, target);;
    }
};
// dp[i]: number of ways to sum upto the target i using the numbers from nums[]  