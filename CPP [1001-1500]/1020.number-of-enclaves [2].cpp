class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        int m=grid.size(), n=grid[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n) // index out bounds
            return;
        if(grid[x][y] != 1) // curr cell is not an unvisited land
            return;
        grid[x][y] = 2; // mark the curr cell as visited
        dfs(grid, x-1, y); // up
        dfs(grid, x+1, y); // down
        dfs(grid, x, y-1); // left
        dfs(grid, x, y+1); // right
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        for(int j=0; j<n; j++) // 0th and (m-1)th row
        {
            dfs(grid, 0, j);
            dfs(grid, m-1, j);
        }
        for(int i=0; i<m; i++) // 0th and (n-1)th col
        {
            dfs(grid, i, 0);
            dfs(grid, i, n-1);
        }
        int ans=0;
        // count the unvisited lands and restore the original grid
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    ans++;
                else if(grid[i][j] == 2)
                    grid[i][j] = 1;
            }
        return ans;
    }
};
/*
# 0: water, 1: unvisited land, 2: visited land
# start from the boundary and mark all the reachable lands as visited
# count the remaining unvisited lands in the grid
*/