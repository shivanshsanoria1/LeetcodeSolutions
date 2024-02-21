class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j){
        int n=grid.size();
        // up, down, left, right
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int, int>> q;
        grid[i][j] = -1; // mark the curr cell as visited
        q.push({i, j});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto dir: dirs)
            {
                int x1 = x + dir.first;
                int y1 = y + dir.second;
                if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) // index out of bounds
                    continue;
                if(grid[x1][y1] == 1) // unvisited land
                    return abs(x1 - i) + abs(y1 - j); // Manhattan distance of nearest land from (i,j)
                if(grid[x1][y1] == -1) // visited water
                    continue;
                grid[x1][y1] = -1; // mark the curr cell as visited
                q.push({x1, y1});
            }
        }
        return -1;
    }

    void resetGrid(vector<vector<int>>& grid){
        int n=grid.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == -1)
                    grid[i][j] = 0;
    }

    int maxDistance(vector<vector<int>>& grid) { // T.C.=O(n^4), S.C.=O(n^2)
        int n=grid.size();
        int ans = -1;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 0) // unvisited water
                    {
                        ans = max(ans, bfs(grid, i, j));
                        resetGrid(grid);
                    }
        return ans;
    }
};
// -1: visited water, 0: unvisited water, 1: land