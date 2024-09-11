class Solution {
private:
    typedef long long int lli;

    lli solve(vector<int>& nums, int i, vector<lli>& dp){
        if(dp[i] != -1)
            return dp[i];

        lli res = 0;
        for(int j=i+1; j<nums.size(); j++)
            res = max(res, (lli)nums[i]*(j-i) + solve(nums, j, dp));

        dp[i] = res;
        return dp[i];
    }

public:
    // T.C.=O(n^2), S.C.=O(n)
    // Memoization
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<lli> dp(n, -1);

        return solve(nums, 0, dp);
    }
};