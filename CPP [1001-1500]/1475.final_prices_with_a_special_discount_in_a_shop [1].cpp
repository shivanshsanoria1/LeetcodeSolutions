class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            bool flag=false;
            for(int j=i+1; j<n; j++)
                if(prices[j] <= prices[i])
                {
                    ans[i]=prices[i]-prices[j];
                    flag=true;
                    break;
                }
            if(flag==false) //no lesser or equal element to the right found
                ans[i]=prices[i];
        }
        return ans;
    }
};