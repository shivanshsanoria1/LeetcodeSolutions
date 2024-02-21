class Solution {
public:
    // returns the sum of values of all water cells reachable from a source cell
    int bfs(vector<vector<int>>& grid, int i, int j){
        if(grid[i][j] <= 0) // land or visited water cell
            return 0;
        int m=grid.size(), n=grid[0].size();
        // directions- up, down, left, right
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int, int>> q;
        grid[i][j] *= -1; // mark the start cell as visited
        q.push({i, j}); // push the start cell in queue
        int sum = 0;
        while(!q.empty())
        {
            auto [currX, currY] = q.front(); // curr cell coordinates
            q.pop();
            sum += abs(grid[currX][currY]); // add the curr cell value to sum
            for(auto [dx, dy]: dirs)
            {
                int x = currX + dx; // next cell x coordinate
                int y = currY + dy; // next cell y coordinate
                if(x < 0 || x >= m || y < 0 || y >= n) // index out of bounds
                    continue;
                if(grid[x][y] == 0) // skip the land cells
                    continue;
                if(grid[x][y] < 0) // skip the visited water cells
                    continue;
                grid[x][y] *= -1; // mark the next cell as visited
                q.push({x, y}); // push the next cell in queue
            }
        }
        return sum;
    }

    void restoreGrid(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] < 0)
                    grid[i][j] *= -1;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans = max(ans, bfs(grid, i, j));
        restoreGrid(grid); // not required
        return ans;
    }
};
// grid[i][j] = 0: land, +ive: unvisited water, -ive: visited water