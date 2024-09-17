class Solution {
private:
    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    int solve(vector<int>& prices, int i, int k, bool canBuy, VEC3D& dp){
        if(i >= prices.size())
            return 0;
        
        if(k == 0)
            return 0;
        
        if(dp[i][k][canBuy] != -1)
            return dp[i][k][canBuy];

        int res = 0;

        int skip = solve(prices, i+1, k, canBuy, dp);

        if(canBuy)
        {
            int buy = solve(prices, i+1, k, !canBuy, dp) - prices[i];
            res = max(skip, buy);
        }
        else
        {
            int sell = solve(prices, i+1, k-1, !canBuy, dp) + prices[i];
            res = max(skip, sell);
        }

        dp[i][k][canBuy] = res;
        return dp[i][k][canBuy];
    }

public:
    // T.C.=O(n*k*2), S.C.=O(n*k*2)
    // DP: Memoization
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        VEC3D dp(n, VEC2D(k+1, VEC1D(2, -1)));

        return solve(prices, 0, k, true, dp);
    }
};

/*
# canBuy = true (buy)
         = false (sell)
# we only need to decrement 'k' while selling, since
  each stock which is to be sold was surely bought previously
*/