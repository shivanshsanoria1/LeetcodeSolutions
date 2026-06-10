class Solution {
public:
    int solve(vector<int>& coins2, int n, vector<int>& dp, int amount)
    {
        if(amount<0)
            return -1;
        if(dp[amount]!=-1) //amount exists in dp[]
            return dp[amount]+1;
        int curr_min=INT_MAX-1, val;
        for(int i=n-1; i>=0; i--)
        {
            val=solve(coins2,n,dp,amount-coins2[i]);
            if(val!=-1)
                curr_min=min(curr_min,val);
        }
        dp[amount]= (curr_min==INT_MAX-1) ? -1 : curr_min;
        return curr_min+1;
    }
    
    int coinChange(vector<int>& coins, int amount) { //recursion + memoization
        vector<int> coins2;
        for(int i=0; i<coins.size(); i++)
            if(coins[i]<=amount)
                coins2.push_back(coins[i]);
        int n=coins2.size();
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=0; i<n; i++)
            dp[coins2[i]]=1;
        int ans=solve(coins2,n,dp,amount);
        for(int i=0; i<amount+1; i++)
            cout<<dp[i]<<" ";
        return ans==INT_MAX ? -1 : ans-1;
    }
};