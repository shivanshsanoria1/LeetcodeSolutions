class Solution {
private:
    long long int dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        
        if(grid[i][j] <= 0)
            return 0;
        
        grid[i][j] *= -1;
        
        int up = dfs(grid, i-1, j);
        int down = dfs(grid, i+1, j);
        int left = dfs(grid, i, j-1);
        int right = dfs(grid, i, j+1);

        return (long long int)grid[i][j] + up + down + left + right;
    }

    void restoreGrid(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                grid[i][j] *= -1;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] <= 0)
                    continue;
                if(dfs(grid, i, j) % k == 0)
                    count++;
            }
                
        // not required
        restoreGrid(grid);
        
        return count;
    }
};