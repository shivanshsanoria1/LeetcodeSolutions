class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) { // Tabulation, T.C.=O(m*n), S.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n)); // m*n dp
        dp[0][0] = grid[0][0]; // fill the first element of dp
        for(int i=1; i<m; i++) // fill the 0th col of dp
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j=1; j<n; j++) // fill the 0th row of dp
            dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        return dp[m-1][n-1];
    }
};