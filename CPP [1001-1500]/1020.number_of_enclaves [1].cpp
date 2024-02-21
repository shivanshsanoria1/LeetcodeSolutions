class Solution {
public:
    int dfs(vector<vector<int>>& grid, bool &flag, int x, int y)
    {
        int m=grid.size(), n=grid[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n) // index out bounds
            return 0;
        if(grid[x][y] != 1) // curr cell is not an unvisited land
            return 0;
        grid[x][y] = 2; // mark the curr cell as visited
        if(x == 0 || x == m-1 || y == 0 || y == n-1) // reached the boundary
            flag = false;
        int up = dfs(grid, flag, x-1, y); // up
        int down = dfs(grid, flag, x+1, y); // down
        int left = dfs(grid, flag, x, y-1); // left
        int right = dfs(grid, flag, x, y+1); // right
        return 1 + up + down + left + right;
    }

    int numEnclaves(vector<vector<int>>& grid) { // DFS
        int ans=0;
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                bool flag = true; // true: include the island size in ans
                int landSize = dfs(grid, flag, i, j);
                ans += flag ? landSize : 0;
            }
        // [Not required] restore the original grid
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 2)
                    grid[i][j] = 1;
        return ans;
    }
};
// 0: water, 1: unvisited land, 2: visited land