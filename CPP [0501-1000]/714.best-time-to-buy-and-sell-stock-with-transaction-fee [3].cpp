class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) { // DP, T.C.=O(n), S.C.=O(1)
        int noStockDP = 0;
        int stockDP = -prices[0]; // buy stock on the 0th day
        for(int i=1; i<prices.size(); i++)
        {
            // profit after selling the ith day stock
            int sell = stockDP + prices[i] - fee;
            // profit after buying the ith day stock
            int buy = noStockDP - prices[i];
            noStockDP = max(noStockDP, sell);
            stockDP = max(stockDP, buy);
        }
        // max profit from n days while not owning stock on the last day
        return noStockDP; 
    }
};
// noStockDP: max profit in the first i days while not owning stock on the ith day
// stockDP: max profit in the first i days while owning stock on the ith day