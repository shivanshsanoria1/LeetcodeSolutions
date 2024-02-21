class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n*target), S.C.=O(target), Tabulation with Space-Optimization
    int numRollsToTarget(int n, int k, int target) {
        if(target < n || target > n*k)
            return 0;

        vector<int> dp_prev(target + 1, 0);
        vector<int> dp_curr(target + 1, 0);
        dp_prev[0] = 1; // to make the solution cleaner

        for(int i=1; i<=n; i++)
        {
            // sum of the last k cols (upto the (j-1)th col) of the prev row
            int sumK = 0;
            for(int j=1; j<=target; j++)
            {
                if(j-k-1 >= 0)
                {
                    sumK = (sumK + dp_prev[j-1] - dp_prev[j-k-1]) % MOD;
                    if(sumK < 0) // keep the sum +ive
                        sumK += MOD;
                }
                else
                    sumK = (sumK + dp_prev[j-1]) % MOD;

                dp_curr[j] = (dp_curr[j] + sumK) % MOD;
            }

            for(int j=0; j<=target; j++)
            {
                // update the prev row with the curr row
                dp_prev[j] = dp_curr[j];
                // reset the curr row
                dp_curr[j] = 0;
            }
        }

        return dp_prev[target];
    }
    /*
    # target value is possible only if it lies in the range [n*1, n*k]
    # dp[i][j]: num of ways to make target j using i dices
    */
};