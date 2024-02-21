class Solution {
public:
    // returns size of island staring from unvisited land index (x,y)
    int dfs(vector<vector<int>>& grid, int x, int y){
        int row=grid.size(), col=grid[0].size();
        if(x<0 || x>=row || y<0 || y>=col) // index out of bounds
            return 0;
        if(grid[x][y] == 0 || grid[x][y] == -1) // curr element is water or visited land
            return 0;
        grid[x][y] = -1; // mark the curr element as visited
        int up = dfs(grid, x-1, y); // up
        int down = dfs(grid, x+1, y); // down
        int left = dfs(grid, x, y-1); // left
        int right = dfs(grid, x, y+1); // right
        return 1 + up + down + left + right;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size(), col=grid[0].size();
        int maxArea = 0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid[i][j] == 1) // curr element is land
                    maxArea = max(maxArea, dfs(grid, i, j));
        // [not required]: restore the original grid
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid[i][j] == -1)
                    grid[i][j] = 1;
        return maxArea;
    }
};
// 0: water, 1: unvisited land, -1: visited land