class Solution {
private:
    // 10^9 + 7
    #define MOD 1000000007

public:
    // retuns the number of the strictly increasing paths starting at (i, j) 
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int parVal){
        int m=grid.size(), n=grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n) // index out of bounds
            return 0;
        // parent value exists and curr val <= par val, ie, invalid path
        if(parVal != -1 && grid[i][j] <= parVal)
            return 0;
        if(dp[i][j] > 0) // solution already present in dp
            return dp[i][j];
        int up = dfs(grid, dp, i-1, j, grid[i][j]);
        int down = dfs(grid, dp, i+1, j, grid[i][j]);
        int left = dfs(grid, dp, i, j-1, grid[i][j]);
        int right = dfs(grid, dp, i, j+1, grid[i][j]);
        dp[i][j] = (1 + up + down + left + right) % MOD; // store the result in dp
        return dp[i][j];
    }

    int countPaths(vector<vector<int>>& grid) { // T.C.=O(m*n), S.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp of size m*n filled with 0's
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                dp[i][j] = dfs(grid, dp, i, j, -1);
                ans = (ans + dp[i][j]) % MOD;
            }
        return ans;
    }
};