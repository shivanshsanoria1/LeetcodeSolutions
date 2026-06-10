class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i >= m || j >= n) // index out of bounds
            return INT_MAX;
        if(dp[i][j] != -1) // result found in dp
            return dp[i][j];
        if(i == m-1 && j == n-1) // reached the bottom-right corner
        {
            dp[i][j] = grid[i][j];
            return dp[i][j];
        }
        int down = solve(grid, dp, i+1, j); // down
        int right = solve(grid, dp, i, j+1); // right
        dp[i][j] = grid[i][j] + min(down, right); // store the result in dp
        return dp[i][j]; 
    }
    
    int minPathSum(vector<vector<int>>& grid) { // Memoization, T.C.=O(m*n), S.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector(n, -1)); // dp of size m*n filled with -1's
        return solve(grid, dp, 0, 0);
    }
};