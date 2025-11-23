class Solution {
private:
    int solve(unordered_map<int, int>& dp, unsigned int n){
        if(n == 1)
            return 0;
        
        // result already in dp
        if(dp.find(n) != dp.end())
            return dp[n];

        //store the result in dp before returning
        if(n % 2 == 0)
            dp[n] = 1 + solve(dp, n/2);
        else
            dp[n] = 1 + min(solve(dp, n+1), solve(dp, n-1));
        
        return dp[n];
    }

public:
    // T.C.=O(??)
    // Memoization
    int integerReplacement(int n) {
        unordered_map<int, int> dp;

        return solve(dp, n);
    }
};