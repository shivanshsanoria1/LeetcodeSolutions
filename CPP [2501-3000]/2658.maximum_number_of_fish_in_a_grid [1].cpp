class Solution {
public:
    // returns the sum of values of all water cells reachable from a source cell 
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n) // index out of bounds
            return 0;
        if(grid[i][j] == 0) // land
            return 0;
        if(grid[i][j] < 0) // visited water
            return 0;
        grid[i][j] *= -1; // mark the curr cell as visited

        int up = dfs(grid, i-1, j);
        int down = dfs(grid, i+1, j);
        int left = dfs(grid, i, j-1);
        int right = dfs(grid, i, j+1);

        return abs(grid[i][j]) + up + down + left + right;
    }

    void restoreGrid(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] < 0)
                    grid[i][j] *= -1;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans = max(ans, dfs(grid, i, j));
        restoreGrid(grid); // not required
        return ans;
    }
};
// grid[i][j] = 0: land, +ive: unvisited water, -ive: visited water