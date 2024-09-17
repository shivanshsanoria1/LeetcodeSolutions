class Solution {
private:
    typedef long long int lli;

public:
    // T.C.=O(4*n), S.C.=O(4*n)
    // DP: Reverse-Tabulation
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<lli>> dp(4+1, vector<lli>(n+1, 0));
        
        for(int i=3; i>=0; i--)
            for(int j=n-1; j>=0; j--)
            {
                lli include = (lli)a[i]*b[j] + dp[i+1][j+1];
                lli exclude = j-i == n-4 ? LLONG_MIN : dp[i][j+1];

                dp[i][j] = max(include, exclude);
            }
        
        return dp[0][0];
    }
};