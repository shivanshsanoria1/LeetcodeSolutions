class Solution {
private:
    typedef pair<int, int> PII;

    long long int bfs(vector<vector<int>>& grid, int startX, int startY){
        int m = grid.size(), n = grid[0].size();
        queue<PII> q;
        // up, down, left, right
        vector<PII> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        long long int sum = grid[startX][startY];

        grid[startX][startY] *= -1;
        q.push({startX, startY});

        while(!q.empty())
        {
            auto [currX, currY] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs)
            {
                int x = currX + dx;
                int y = currY + dy;

                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if(grid[x][y] <= 0)
                    continue;
                
                sum += grid[x][y];
                grid[x][y] *= -1;
                
                q.push({x, y});
            }
        }

        return sum;
    }

    void restoreGrid(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                grid[i][j] *= -1;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] <= 0)
                    continue;
                if(bfs(grid, i, j) % k == 0)
                    count++;
            }
                
        // not required
        restoreGrid(grid);
        
        return count;
    }
};