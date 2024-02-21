class Solution {
public:
    int solve(vector<int>& coins, vector<vector<int>>& dp, int i, int amount){
        if(i >= coins.size()) // index out of bounds
            return 0;
        if(amount < 0) // reached over the target amount
            return 0;
        if(amount == 0) // reached the target amount
        {
            dp[i][amount] = 1;
            return dp[i][amount];
        }
        if(dp[i][amount] != -1) // solution found in dp
            return dp[i][amount];
        // include coin at index i, ie, remain at the same index (so that coins[i] can possibly be chosen again)
        int include = solve(coins, dp, i, amount - coins[i]);
        // exclude coin at index i, ie, move to the next index (so that coins[i] can never be chosen again)
        int exclude = solve(coins, dp, i + 1, amount);
        dp[i][amount] = include + exclude; // store the solution in dp
        return dp[i][amount];
    }

    int change(int amount, vector<int>& coins) { // Memoization, T.C.=O(coins*amount), S.C.=O(coins*amount)
        int n=coins.size();
        // dp of size coins*(amount + 1) filled with -1's
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        solve(coins, dp, 0, amount);
        return dp[0][amount];
    }
};
// dp[i][j] tells number of ways to make the amount j using coins from index n-1 to i