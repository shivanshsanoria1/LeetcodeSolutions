class Solution {
public:
    int min_coins=INT_MAX;
    void solve(vector<int>& coins, int n, int amount, int count)
    {
        if(amount<0)
            return;
        if(amount==0)
        {
            min_coins=min(min_coins,count);
            return;
        }
        for(int i=n-1; i>=0; i--)
        {
            solve(coins,n,amount-coins[i],count+1);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) { //recursion
        solve(coins,coins.size(),amount,0);
        return min_coins==INT_MAX ? -1 : min_coins;
    }
};