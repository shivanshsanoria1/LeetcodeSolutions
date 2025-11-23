class Solution {
public:
    int maxProfit(vector<int>& prices) { // T.C.=O(n)
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int price: prices)
        {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return maxProfit;
    }
};