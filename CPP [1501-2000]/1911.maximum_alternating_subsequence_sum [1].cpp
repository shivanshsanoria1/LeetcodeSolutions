class Solution {
private:
    typedef long long int lli;

public:
    lli solve(vector<vector<lli>>& dp, vector<int>& nums, int i, bool isPos){
        if(i == nums.size())
            return 0;
        if(dp[i][isPos] != -1)
            return dp[i][isPos];
        int sign = isPos ? 1 : -1;
        lli include = sign*nums[i] + solve(dp, nums, i+1, !isPos);
        lli exclude = solve(dp, nums, i+1, isPos);
        dp[i][isPos] = max(include, exclude);
        return dp[i][isPos]; 
    }

    long long maxAlternatingSum(vector<int>& nums) { // Memoization, T.C.=O(n), S.C.=O(n)
        int n=nums.size();
        // dp of size n*2 filled with -1's
        vector<vector<lli>> dp(n, vector<lli>(2, -1));
        return solve(dp, nums, 0, true);
    }
};
// isPos = true -> +ive, isPos = false -> -ive