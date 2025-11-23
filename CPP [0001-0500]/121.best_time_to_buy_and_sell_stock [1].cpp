class Solution {
public:
    int maxProfit(vector<int>& prices) { // T.C.=O(n)
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int price: prices)
        {
            // new min price found
            if(price < minPrice) 
                minPrice = price;
            // new max profit found
            else if(price - minPrice > maxProfit)
                maxProfit = price - minPrice;
        }
        return maxProfit;
    }
};