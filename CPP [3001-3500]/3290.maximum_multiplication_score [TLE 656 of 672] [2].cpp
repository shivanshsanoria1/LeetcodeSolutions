class Solution {
private:
    #define INF LLONG_MIN
    typedef long long int lli;

    lli solve(vector<int>& a, vector<int>& b, int i, int j, vector<vector<lli>>& dp){
        if(i == 4 || j == b.size())
            return 0;
        
        if(dp[i][j] != INF)
            return dp[i][j];

        lli res = INF;
        for(int k=j; k <= b.size()-4+i; k++)
            res = max(res, (lli)a[i]*b[k] + solve(a, b, i+1, k+1, dp));

        dp[i][j] = res;
        return dp[i][j];
    }

public:
    // T.C.=O(), S.C.=O()
    // DP: Memoization
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<lli>> dp(4, vector<lli>(n, INF));

        return solve(a, b, 0, 0, dp);
    }
};