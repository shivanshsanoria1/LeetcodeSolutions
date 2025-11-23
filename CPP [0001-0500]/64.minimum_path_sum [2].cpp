class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) { // Tabulation, T.C.=O(m*n), S.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, INT_MAX)); // (m+1)*(n+1) dp filled with INT_MAX's
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {
                if(dp[i-1][j] == INT_MAX && dp[i][j-1] == INT_MAX)
                    dp[i][j] = grid[i-1][j-1];
                else
                    dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
            }
        return dp[m][n];
    }
};
// dp[i][j] is mapped with grid[i-1][j-1]
// 0th row and 0th col is filled with INT_MAX's
