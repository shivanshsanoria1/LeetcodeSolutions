class Solution {
private:
    int solve(vector<vector<char>>& matrix, vector<vector<int>>& dp, int i, int j){
        int m=matrix.size(), n=matrix[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int south = solve(matrix, dp, i+1, j);
        int east = solve(matrix, dp, i, j+1); 
        int southEast = solve(matrix, dp, i+1, j+1); 
        
        dp[i][j] = matrix[i][j] == '1' ? 1 + min(southEast, min(south, east)) : 0;

        return dp[i][j];
    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // DP-Memoization
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        solve(matrix, dp, 0, 0);

        int maxSideLen = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                maxSideLen = max(maxSideLen, dp[i][j]);

        return maxSideLen * maxSideLen;
    }
};
// dp[i][j]: max side length of square with top-left corner at (i, j) 