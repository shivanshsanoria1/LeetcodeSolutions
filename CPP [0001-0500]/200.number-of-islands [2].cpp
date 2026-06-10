class Solution {
private:
    typedef pair<int, int> PII;
    
    void bfs(vector<vector<char>>& grid, int startX, int startY){
        int m=grid.size(), n=grid[0].size();

        // up, down, left, right
        vector<PII> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        queue<PII> q;
        // mark the start cell as visited
        grid[startX][startY] = '2';
        q.push({startX, startY});

        while(!q.empty())
        {
            auto [currX, currY] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs) 
            {
                int x = currX + dx;
                int y = currY + dy;
                // index out of bounds
                if(x<0 || x>=m || y<0 || y>=n) 
                    continue;
                // next cell is not unvisited-land
                if(grid[x][y] != '1')
                    continue; 
                // mark the next cell as visited
                grid[x][y] = '2'; 
                q.push({x, y});
            }
        }
    }

    void restoreGrid(vector<vector<char>>& grid){
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == '2')
                    grid[i][j] = '1';
    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int islands = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    islands++;
                }

        restoreGrid(grid);

        return islands;
    }
};
// 0: water, 1: unvisited-land, 2: visited-land