class Solution {
private:
    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

public:
    int solve(vector<int>& prices, VEC3D& dp, int i, bool canBuy, int limit){
        if(limit == 0)
            return 0;
        if(i == prices.size())
            return 0;
        if(dp[i][canBuy][limit] != -1)
            return dp[i][canBuy][limit];
        int skip = solve(prices, dp, i+1, canBuy, limit);
        if(canBuy)
        {
            int buy = solve(prices, dp, i+1, !canBuy, limit) - prices[i];
            dp[i][canBuy][limit] = max(skip, buy);
        }
        else
        {
            int sell = solve(prices, dp, i+1, !canBuy, limit-1) + prices[i];
            dp[i][canBuy][limit] = max(skip, sell);
        }
        return dp[i][canBuy][limit];
    }

    int maxProfit(vector<int>& prices) { // Memoization, T.C.=O(6*n), S.C.=O(6*n)
        int n=prices.size();
        // dp of size n*2*3 filled with -1's
        VEC3D dp(n, VEC2D(2, VEC1D(3, -1)));
        return solve(prices, dp, 0, true, 2);
    }
};
// canBuy = true: buy, false: sell