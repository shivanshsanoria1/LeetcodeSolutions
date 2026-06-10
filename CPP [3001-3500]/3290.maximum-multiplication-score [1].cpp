class Solution {
private:
    #define INF LLONG_MIN
    typedef long long int lli;

    lli solve(vector<int>& a, vector<int>& b, int i, int j, vector<vector<lli>>& dp){
        int n=b.size();
        if(i == 4 || j == n)
            return 0;
        
        if(dp[i][j] != INF)
            return dp[i][j];
        
        lli include = (lli)a[i]*b[j] + solve(a, b, i+1, j+1, dp);
        lli exclude = j-i == n-4 ? INF : solve(a, b, i, j+1, dp);

        dp[i][j] = max(include, exclude);
        return dp[i][j]; 
    }

public:
    // T.C.=O(4*n), S.C.=O(4*n)
    // DP: Memoization
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<lli>> dp(4, vector<lli>(n, INF));

        return solve(a, b, 0, 0, dp);
    }
};