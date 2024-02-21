class Solution {
public:
    int solve(vector<int>& prices, int fee, vector<vector<int>>& dp, int i, bool canBuy){
        if(i >= prices.size())
            return 0;
        if(dp[i][canBuy] != -1)
            return dp[i][canBuy];
        int skip = solve(prices, fee, dp, i+1, canBuy);
        if(canBuy)
        {
            int buy = solve(prices, fee, dp, i+1, !canBuy) - prices[i];
            dp[i][canBuy] = max(skip, buy);
        }
        else
        {
            int sell = solve(prices, fee, dp, i+1, !canBuy) + prices[i] - fee;
            dp[i][canBuy] = max(skip, sell);
        }
        return dp[i][canBuy];
    }

    int maxProfit(vector<int>& prices, int fee) { // Memoization, T.C.=O(n), S.C.=O(n)
        int n=prices.size();
        // dp of size n*2 filled with -1's
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, fee, dp, 0, true);
    }
};
// canBuy = true: buy, false: sell