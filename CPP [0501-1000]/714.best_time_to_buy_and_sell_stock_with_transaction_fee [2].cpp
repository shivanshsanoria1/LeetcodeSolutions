class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) { // DP, T.C.=O(n), S.C.=O(n)
        int n=prices.size();
        vector<int> noStockDP(n, 0);
        vector<int> stockDP(n, 0);
        stockDP[0] = -prices[0]; // buy stock on the 0th day
        for(int i=1; i<n; i++)
        {
            // profit after selling the ith day stock
            int sell = stockDP[i-1] + prices[i] - fee;
            // profit after buying the ith day stock
            int buy = noStockDP[i-1] - prices[i];
            noStockDP[i] = max(noStockDP[i-1], sell);
            stockDP[i] = max(stockDP[i-1], buy);
        }
        // max profit from n days while not owning stock on the last day
        return noStockDP[n-1]; 
    }
};
// noStockDP[i]: max profit in the first i days while not owning stock on the ith day
// stockDP[i]: max profit in the first i days while owning stock on the ith day