class Solution {
public:
    int solve(vector<int>& prices, int fee, int i, bool prev, int val){
        if(i == prices.size())
            return val;
        int buyOrSell = 0;
        if(prev) // prev step was sell
            buyOrSell = solve(prices, fee, i+1, false, val - prices[i]); // buy
        else // prev step was buy
            buyOrSell = solve(prices, fee, i+1, true, val + prices[i] - fee); // sell
        int skip = solve(prices, fee, i+1, prev, val); // skip
        return max(buyOrSell, skip);
    }

    int maxProfit(vector<int>& prices, int fee) { // Recursion
        return solve(prices, fee, 0, true, 0);
    }
};
/*
# prev = false -> buy, true -> sell
# prev is initialized with true, ie, sell, because in the very first step 
# we can only buy or skip stock so prev step must have been sell 
*/