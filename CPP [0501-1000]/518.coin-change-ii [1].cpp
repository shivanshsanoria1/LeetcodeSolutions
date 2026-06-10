class Solution {
public:
    int change(int amount, vector<int>& coins) { // DP, T.C.=O(coins*amount), S.C.=O(coins*amount)
        int n=coins.size();
        // dp of size (n+1)*(amount+1)
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

        // 0 ways to make non-zero amount with 0 value coin
        for(int j=0; j<=amount; j++) // 0th row filled with 0's
            dp[0][j] = 0;
        // 1 way to make 0 amount with any value coin, ie, excluding that coin
        for(int i=0; i<=n; i++) // 0th col filled with 1's
            dp[i][0] = 1;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=amount; j++)
            {
                // including the curr coin means staying at the samew row and 
                // reducing the amount to j - coins[i-1]
                int include = (j - coins[i-1] >= 0) ? dp[i][j - coins[i-1]] : 0;
                // excluding the curr coin means moving to the prev row
                int exclude = dp[i-1][j];
                dp[i][j] = include + exclude;
            }

        return dp[n][amount];
    }
};
/*
# dp[0][0] is initialized with 1
# coin at index i in dp[][] is mapped with index i-1 in coins[]
# dp[i][j] tells number of ways to make the amount j using coins from index 0 to i-1 in coins[]
*/