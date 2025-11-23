class Solution {
public:
    int coinChange(vector<int>& coins, int amount) { // DP, T.C.=O(n*amount), S.C.=O(n*amount)
        int n= coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1)); // (n+1)*(amount+1) dp
        for(int j=1; j<amount+1; j++) // 0th row
            dp[0][j] = INT_MAX-1;
        for(int i=0; i<n+1; i++) // 0th col
            dp[i][0] = 0;
        for(int i=1; i<n+1; i++)
            for(int j=1; j<amount+1; j++)
            {
                if(coins[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
            }
        return dp[n][amount]==INT_MAX-1 ? -1 : dp[n][amount];
    }
};