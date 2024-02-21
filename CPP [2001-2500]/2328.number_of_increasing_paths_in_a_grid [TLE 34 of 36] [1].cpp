class Solution {
public:
    // retuns the number of the strictly increasing paths starting at (i, j) 
    int dfs(vector<vector<int>>& grid, int i, int j, int parVal){
        int m=grid.size(), n=grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n) // index out of bounds
            return 0;
        // parent value exists and curr val <= par val, ie, invalid path
        if(parVal != -1 && grid[i][j] <= parVal) 
            return 0;
        int up = dfs(grid, i-1, j, grid[i][j]);
        int down = dfs(grid, i+1, j, grid[i][j]);
        int left = dfs(grid, i, j-1, grid[i][j]);
        int right = dfs(grid, i, j+1, grid[i][j]);
        return 1 + up + down + left + right;
    }

    int countPaths(vector<vector<int>>& grid) { // T.C.=O((m*n)^2), S.C.=O(1)
        int m=grid.size(), n=grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans += dfs(grid, i, j, -1);
        return ans;
    }
};