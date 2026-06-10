class Solution {
public:
    // returns true if curr island is a closed island
    bool dfs(vector<vector<int>>& grid, int x, int y){
        int m=grid.size(), n=grid[0].size();
        if(x<0 || x>=m || y<0 || y>=n) // index out of bounds
            return false;
        if(grid[x][y] != 0) // curr element is water or unvisited land
            return true;
        grid[x][y] = -1; // mark the curr land as visited
        bool up = dfs(grid, x-1, y); // up
        bool down = dfs(grid, x+1, y); // down
        bool left = dfs(grid, x, y-1); // left
        bool right = dfs(grid, x, y+1); // right
        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) { // T.C.=O(m*n), S.C.=O(1)
        int m=grid.size(), n=grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 0) // curr element is unvisited land
                    ans += dfs(grid, i, j);
        // [Not required]: restore the original grid
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == -1)
                    grid[i][j] = 0;
        return ans;
    }
};
// -1: visited land, 0: unvisited land, 1: water
// if any island boundaries with the edge of the grid then it is not a closed island