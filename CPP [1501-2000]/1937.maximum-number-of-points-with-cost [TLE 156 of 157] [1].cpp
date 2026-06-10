class Solution {
private:
    typedef long long int lli;

public:
    // T.C.=O(m*n^2), S.C.=O(m*n)
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size(), n=points[0].size();
        vector<vector<lli>> dp(m, vector<lli>(n, 0));

        for(int j=0; j<n; j++)
            dp[0][j] = points[0][j]; 

        for(int i=1; i<m; i++)
            for(int j=0; j<n; j++)
            {
                lli prevRowMax = LLONG_MIN;
                for(int k=0; k<n; k++)
                    prevRowMax = max(prevRowMax, dp[i-1][k] - abs(j - k));

                dp[i][j] = points[i][j] + prevRowMax;
            }
        
        return *max_element(dp.back().begin(), dp.back().end());
    }
};