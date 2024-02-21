class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n) // index out of bounds
            return 0;
        if(grid[i][j] != 1) // not unvisited land
            return 0;
        grid[i][j] *= -1; // mark the curr land as visited

        int up = dfs(grid, i-1, j); // up
        int down = dfs(grid, i+1, j); // down
        int left = dfs(grid, i, j-1); // left
        int right = dfs(grid, i, j+1); // right

        return 1 + up + down + left + right;
    }

    void restoreGrid(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] < 0)
                    grid[i][j] *= -1;
    }

    int minDays(vector<vector<int>>& grid) { // T.C.=O((m*n)^2), S.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        int islands = 0, islandSize = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] != 1)
                    continue;
                if(islands == 1) // more than 1 island found in the grid initially
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
                grid[skip_i][skip_j] = 0; // convert land to water
                int currIslandSize = 0;
                for(int i=0; i<m; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(grid[i][j] != 1)
                            continue;
                        currIslandSize = dfs(grid, i, j);
                    }
                    if(1 + currIslandSize != islandSize)
                        return 1;
                }
                grid[skip_i][skip_j] = 1; // convert water back to land 
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

# for islandSize = 0, num of days to disconnect it is 0
# for islandSize = 1, num of days to disconnect it is 1
# for islandSize = 2, num of days to disconnect it is 2
*/