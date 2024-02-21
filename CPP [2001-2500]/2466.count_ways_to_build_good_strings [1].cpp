class Solution {
private:
    // 10^9 + 7
    #define MOD 1000000007

public:
    int solve(int low, int high, int zero, int one, vector<int>& dp, int currLen){
        if(currLen > high)
            return 0;
        if(dp[currLen] != -1) // solution already exists in dp
            return dp[currLen];
        if(currLen == high)
        {
            dp[currLen] = 1;
            return dp[currLen];
        }
        int left = solve(low, high, zero, one, dp, currLen + zero);
        int right = solve(low, high, zero, one, dp, currLen + one);
        dp[currLen] = currLen >= low ? (1 + left + right) % MOD : (left + right) % MOD;
        return dp[currLen];
    }

    int countGoodStrings(int low, int high, int zero, int one) { // Memoization, T.C.=O(high), S.C.=O(high)
        vector<int> dp(high + 1, -1); // dp of size (high + 1) filled with -1's
        return solve(low, high, zero, one, dp, 0);
    }
};