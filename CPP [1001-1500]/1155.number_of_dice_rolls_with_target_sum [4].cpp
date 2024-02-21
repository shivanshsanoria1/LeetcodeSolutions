class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n*target), S.C.=O(n*target), Tabulation
    int numRollsToTarget(int n, int k, int target) {
        if(target < n || target > n*k)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1; // to make the solution cleaner

        for(int i=1; i<=n; i++)
        {
            // sum of the last k cols (upto the (j-1)th col) of the prev row
            int sumK = 0;
            for(int j=1; j<=target; j++)
            {
                if(j-k-1 >= 0)
                {
                    sumK = (sumK + dp[i-1][j-1] - dp[i-1][j-k-1]) % MOD;
                    if(sumK < 0) // keep the sum +ive
                        sumK += MOD;
                }
                else
                    sumK = (sumK + dp[i-1][j-1]) % MOD;

                dp[i][j] = (dp[i][j] + sumK) % MOD;
            }
        }
        
        return dp[n][target];
    }
    /*
    # target value is possible only if it lies in the range [n*1, n*k]
    # dp[i][j]: num of ways to make target j using i dices
    */
};