class Solution {
public:
    typedef pair<int, int> PI;

    // returns the coordinates of island staring from unvisited land index (x,y)
    int dfs(vector<vector<int>>& grid, vector<PI> &island, int x, int y){
        int row=grid.size(), col=grid[0].size();
        if(x<0 || x>=row || y<0 || y>=col) // index out of bounds
            return 0;
        if(grid[x][y] == 0 || grid[x][y] == -1) // curr element is water or visited land
            return 0;
        grid[x][y] = -1; // mark the curr element as visited
        island.push_back({x, y}); // push the coordinates of curr element in 'island' vector
        int up = dfs(grid, island, x-1, y); // up
        int down = dfs(grid, island, x+1, y); // down
        int left = dfs(grid, island, x, y-1); // left
        int right = dfs(grid, island, x, y+1); // right
        return 1 + up + down + left + right;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<PI> island; // to store the coordinates of an island
        vector<vector<PI>> islands2; // to store the islands of grid2
        int row=grid1.size(), col=grid1[0].size();
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid2[i][j] == 1) // curr element is unvisited land
                {
                    dfs(grid2, island, i, j);
                    if(island.size() > 0)
                    {
                        islands2.push_back(island);
                        island.clear(); // clear the island vector for the next island
                    }
                }

        int ans = 0;
        for(auto island: islands2)
        {
            bool flag = true;
            for(auto coor: island)
            {
                if(grid1[coor.first][coor.second] == 0) // corresponding element in grid1 is water
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true) // sub-island found in grid2
                ans++;
        }

        // [Not required]: restore the original grids
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid1[i][j] == -1)
                    grid1[i][j] = 1;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid2[i][j] == -1)
                    grid2[i][j] = 1;

        return ans;
    }
};
// 0: water, 1: unvisited land, -1: visited land