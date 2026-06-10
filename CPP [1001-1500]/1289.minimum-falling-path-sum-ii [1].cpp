class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int prevCol, vector<vector<int>>& dp){
        int n=grid.size();

        if(i >= n)
            return 0;
        
        if(dp[i][prevCol + 1] != -1)
            return dp[i][prevCol + 1];
        
        int minSum = INT_MAX;

        for(int j=0; j<n; j++)
            if(j != prevCol)
                minSum = min(minSum, grid[i][j] + solve(grid, i+1, j, dp));

        dp[i][prevCol + 1] = minSum;
        return dp[i][prevCol + 1];
    }

public:
    // T.C.=O(n^2), S.C.=O(n^2)
    // DP-Memoization
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(grid, 0, -1, dp);
    }
};
// [prevCol + 1] is used in dp to convert -1 based into 0 based indexing