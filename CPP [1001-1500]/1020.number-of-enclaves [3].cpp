class Solution {
public:
    void bfs(vector<vector<int>>& grid, int x, int y)
    {
        if(grid[x][y] != 1) // not unvisited land
            return;
        int m=grid.size(), n=grid[0].size();
        // up, down, left, right
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int, int>> q;
        grid[x][y] = 2; // mark the curr cell as visited
        q.push({x, y});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto dir: dirs)
            {
                int x1 = x + dir.first;
                int y1 = y + dir.second;
                if(x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) // index out of bounds
                    continue;
                if(grid[x1][y1] != 1) // not unvisited land
                    continue;
                grid[x1][y1] = 2;
                q.push({x1, y1});
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        for(int j=0; j<n; j++) // 0th and (m-1)th row
        {
            bfs(grid, 0, j);
            bfs(grid, m-1, j);
        }
        for(int i=0; i<m; i++) // 0th and (n-1)th col
        {
            bfs(grid, i, 0);
            bfs(grid, i, n-1);
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