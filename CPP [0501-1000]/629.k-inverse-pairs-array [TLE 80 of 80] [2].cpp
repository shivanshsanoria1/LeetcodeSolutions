class Solution {
private:
    #define MOD int(1e9 + 7)

    int solve(vector<vector<int>> &dp, int n, int k){
        if(n == 0)
            return k == 0 ? 1 : 0;
        if(k < 0)
            return 0;

        if(dp[n][k] != -1)
            return dp[n][k];

        int sum = 0;
        for(int i=1; i<=n; i++)
            sum = (sum + solve(dp, n-1, k-i+1)) % MOD;
        
        dp[n][k] = sum;
        return dp[n][k];
    }

public:
    // T.C.=O(n^2*k), S.C.=O(n*k), Memoization
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(dp, n, k);
    }
};