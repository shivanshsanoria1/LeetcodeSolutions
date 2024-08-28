class Solution {
private:
    typedef pair<int, int> PII;

    void bfs(vector<vector<int>>& grid, int startX, int startY, vector<vector<PII>>& islands){
        int m=grid.size(), n=grid[0].size();
        // up, down, left, right
        vector<PII> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<PII> island;

        queue<PII> q;
        grid[startX][startY] = -1;
        q.push({startX, startY});

        while(!q.empty())
        {
            auto [currX, currY] = q.front();
            q.pop();

            island.push_back({currX, currY});

            for(auto [dx, dy]: dirs)
            {
                int x = currX + dx;
                int y = currY + dy;

                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if(grid[x][y] != 1)
                    continue;

                grid[x][y] = -1;
                q.push({x, y});
            }
        }

        islands.push_back(island);
    }

    void restoreGrid(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == -1)
                    grid[i][j] = 1;
    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(), n=grid1[0].size();
        
        // store the coordinates of lands that make up island in grid2
        vector<vector<PII>> islands2;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid2[i][j] == 1)
                    bfs(grid2, i, j, islands2);
        
        // check if each island of grid2 is a sub-island of grid1
        int subIslands = 0;
        for(vector<PII>& island: islands2)
        {
            bool isSubIsland = true;
            for(auto [i, j]: island)
                if(grid1[i][j] != 1)
                {
                    isSubIsland = false;
                    break;
                }

            if(isSubIsland)
                subIslands++;
        }

        // not required
        restoreGrid(grid2);

        return subIslands;
    }
};
// 0: water, 1: unvisited land, -1: visited land