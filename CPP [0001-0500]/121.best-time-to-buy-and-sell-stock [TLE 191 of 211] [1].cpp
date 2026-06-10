class Solution {
public:
    int maxProfit(vector<int>& prices) { // T.C.=O(n^2)
        int n=prices.size();
        int maxProfit = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                maxProfit = max(maxProfit, prices[j] - prices[i]);
        return maxProfit;
    }
};