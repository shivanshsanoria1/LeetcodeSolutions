class Solution {
public:
    int solve(vector<int>& prices, int i, int profit, bool prev){
        if(i >= prices.size())
            return profit;
        int skip = solve(prices, i+1, profit, prev);
        int buy = prev ? solve(prices, i+1, profit - prices[i], !prev) : INT_MIN;
        int sell = !prev ? solve(prices, i+2, profit + prices[i], !prev) : INT_MIN;
        return max(skip, max(buy, sell));
    }

    int maxProfit(vector<int>& prices) { // Recursion
        return solve(prices, 0, 0, true);
    }
};
// prev = true: sell, false: buy