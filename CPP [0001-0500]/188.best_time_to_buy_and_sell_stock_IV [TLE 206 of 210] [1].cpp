class Solution {
private:
    int solve(vector<int>& prices, int i, int k, bool canBuy){
        if(i >= prices.size())
            return 0;
        
        if(k == 0)
            return 0;

        int res = 0;

        int skip = solve(prices, i+1, k, canBuy);

        if(canBuy)
        {
            int buy = solve(prices, i+1, k, !canBuy) - prices[i];
            res = max(skip, buy);
        }
        else
        {
            int sell = solve(prices, i+1, k-1, !canBuy) + prices[i];
            res = max(skip, sell);
        }

        return res;
    }

public:
    // Recursion
    int maxProfit(int k, vector<int>& prices) {    
        return solve(prices, 0, k, true);
    }
};

/*
# canBuy = true (buy)
         = false (sell)
# we only need to decrement 'k' while selling, since
  each stock which is to be sold was surely bought previously
*/