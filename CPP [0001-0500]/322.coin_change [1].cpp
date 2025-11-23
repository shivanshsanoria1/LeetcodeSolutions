class Solution {
public:
    int solve(vector<int>& coins, int n, vector<int>& dp, int d, int amount)
    {
        if(amount < 0)
            return INT_MAX-1;
        if(dp[amount] != -1) //amount already exists in dp[]
            return 1 + dp[amount];
        int min_coins= INT_MAX-1;
        for(int i=0; i<n; i++)
            min_coins= min(min_coins, solve(coins,n,dp,d,amount-coins[i]));
        dp[amount]= min_coins; //store the min coins for curr amount in dp[]
        return 1 + dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) { //DFS + memoization
        int n=coins.size();
        vector<int> dp(amount+1,-1); //i: amount , dp[i]: min num of coins required to make that amount
        int d=dp.size();
        dp[0]=0; //0 coins are required to make amount 0
        for(int i=0; i<n; i++)
            if(coins[i] <= amount) //coins[i] exists in dp[]
                dp[coins[i]]=1; //1 coin is required to make amount coins[i]
        solve(coins,n,dp,d,amount);
        return dp[amount]==INT_MAX-1 ? -1 : dp[amount];
    }
};
//INT_MAX-1 is used instead of INT_MAX to prevent int overflow
