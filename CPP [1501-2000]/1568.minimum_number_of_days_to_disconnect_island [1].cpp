class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        // index out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n) 
            return 0;
        // not unvisited land
        if(grid[i][j] != 1) 
            return 0;
        // mark the curr land as visited
        grid[i][j] *= -1; 

        int up = dfs(grid, i-1, j);
        int down = dfs(grid, i+1, j);
        int left = dfs(grid, i, j-1);
        int right = dfs(grid, i, j+1);

        return 1 + up + down + left + right;
    }

    void restoreGrid(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] < 0)
                    grid[i][j] *= -1;
    }

public:
    // T.C.=O((m*n)^2), S.C.=O(m*n)
    int minDays(vector<vector<int>>& grid) { 
        int m=grid.size(), n=grid[0].size();
        int islands = 0, islandSize = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] != 1)
                    continue;
                // more than 1 island found in the grid initially
                if(islands == 1) 
                {
                    restoreGrid(grid);
                    return 0;
                }
                islandSize = dfs(grid, i, j);
                islands++;
            }

        restoreGrid(grid);
        if(islandSize <= 2)
            return islandSize;

        for(int skip_i = 0; skip_i < m; skip_i++)
            for(int skip_j = 0; skip_j < n; skip_j++)
            {
                if(grid[skip_i][skip_j] != 1)
                    continue;
                // convert land to water
                grid[skip_i][skip_j] = 0; 
                int currIslandSize = 0;
                for(int i=0; i<m; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(grid[i][j] != 1)
                            continue;
                        currIslandSize = dfs(grid, i, j);
                    }
                    // converting the land at {skip_i, skip_j} 
                    // to water disconnects the island
                    if(1 + currIslandSize != islandSize)
                        return 1;
                }
                // convert water back to land 
                grid[skip_i][skip_j] = 1; 
                restoreGrid(grid);
            }

        return 2;
    }
};
/*
# 0: water, 1: unvisited land, -1: visited land

# Return 0 if the grid is already disconnected.
# Return 1 if changing a single land to water disconnect the island.
# Otherwise return 2.
# There is no case where more than 2 land removals 
  are needed to disconnect the island

# for islandSize = 0, num of days to disconnect it is 0
# for islandSize = 1, num of days to disconnect it is 1
# for islandSize = 2, num of days to disconnect it is 2
*/