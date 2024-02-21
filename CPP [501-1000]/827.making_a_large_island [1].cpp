class Solution {
public:
    // returns the number of land cells reachable from a source land cell
    int dfs1(vector<vector<int>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= m) // index out of bounds
            return 0;
        if(grid[i][j] != 1) // skip the cells that are not unvisited land
            return 0; 
        grid[i][j] = 2; // mark the curr land as visited
        int up = dfs1(grid, i-1, j);
        int down = dfs1(grid, i+1, j);
        int left = dfs1(grid, i, j-1);
        int right = dfs1(grid, i, j+1);
        return 1 + up + down + left + right;
    }

    // fills the already visited land cells with their unique island id
    void dfs2(vector<vector<int>>& grid, int islandId, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= m) // index out of bounds
            return;
        if(grid[i][j] != 2) // skip the cells that are not visited land
            return;
        grid[i][j] = islandId; // fill the islandId in curr land cell
        dfs2(grid, islandId, i-1, j); // up
        dfs2(grid, islandId, i+1, j); // down 
        dfs2(grid, islandId, i, j-1); // left
        dfs2(grid, islandId, i, j+1); // right
    } 

    // restores the original grid
    void restoreGrid(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] < 0)
                    grid[i][j] = 1;
    }

    int largestIsland(vector<vector<int>>& grid) { // T.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        unordered_map<int, int> mp; // islandId -> islandSize
        int islandId = 0;
        int landCount = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] != 0) // not a water cell
                    landCount++;
                if(grid[i][j] != 1) // skip the cells that are not unvisited land
                    continue;
                // get the island size starting from land cell (i,j)
                int islandSize = dfs1(grid, i, j); 
                islandId--;
                mp[islandId] = islandSize;
                // fill the island id in all land cells of the curr island
                dfs2(grid, islandId, i, j); 
            }
        if(landCount == m*n) // all the cells are land
        {
            restoreGrid(grid); // not required
            return m*n;
        }
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] != 0) // skip the cells that are not water
                    continue;
                unordered_map<int, int> uniqueIslands; // islandId -> islandSize
                // directions- up, down, left, right
                vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
                for(auto [dx, dy]: dirs)
                {
                    int x = i + dx; // neighbour cell x coordinate
                    int y = j + dy; // neighbour cell y coordinate
                    if(x < 0 || x >= m || y < 0 || y >= m) // index out of bounds
                        continue;
                    if(grid[x][y] == 0) // skip the water cells
                        continue;
                    int islandId = grid[x][y];
                    int islandSize = mp[grid[x][y]];
                    uniqueIslands[islandId] = islandSize;
                }
                // add the size of all unique islands that are 4-directionally connected to curr water cell
                int increasedIslandSize = 1;
                for(auto [islandId, islandSize]: uniqueIslands)
                    increasedIslandSize += islandSize;
                ans = max(ans, increasedIslandSize);
            }
        restoreGrid(grid); // not required
        return ans;
    }
};
// grid[i][j] = 0: water, 1: unvisited land, 2: visited land, -ive: islandId