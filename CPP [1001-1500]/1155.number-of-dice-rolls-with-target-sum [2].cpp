class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n*target*k), S.C.=O(n*target), Tabulation
    int numRollsToTarget(int n, int k, int target) {
        if(target < n || target > n*k)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1; // to make the solution cleaner

        for(int i=1; i<=n; i++)
            for(int j=1; j<=target; j++)
                // sum the last k cols (upto the (j-1)th col) of the prev row
                for(int l=max(0, j - k); l < j; l++)
                    dp[i][j] = (dp[i][j] + dp[i-1][l]) % MOD;
                
        return dp[n][target];
    }
    /*
    # target value is possible only if it lies in the range [n*1, n*k]
    # dp[i][j]: num of ways to make target j using i dices
    */
};