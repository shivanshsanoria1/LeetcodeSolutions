class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) { // DP
        vector<unsigned int> dp(target + 1, 0); // unsigned int is used instead of int to prevent overflow
        dp[0] = 1;
        for(int i=1; i<=target; i++)
            for(int num: nums)
            {
                if(i - num < 0)
                    continue;
                dp[i] += dp[i - num];
            }
        return dp[target];
    }
};
// dp[i]: number of ways to sum upto the target i using the numbers from nums[]  