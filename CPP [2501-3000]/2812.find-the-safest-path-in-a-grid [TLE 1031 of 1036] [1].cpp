class Solution {
private:
    void multiSourceBFS(vector<vector<int>>& grid, vector<vector<int>>& dist, vector<vector<bool>>& visited, queue<pair<int, int>>& q){
        int n=grid.size();

        // up, down, left, right directions
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int level = 0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto [currX, currY] = q.front();
                q.pop();
                
                dist[currX][currY] = level;

                for(auto [dx, dy]: dirs)
                {
                    int x = currX + dx;
                    int y = currY + dy;

                    if(x < 0 || x >= n || y < 0 || y >= n)
                        continue;
                    if(visited[x][y])
                        continue;

                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
                
            level++;
        }
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& dist, vector<vector<bool>>& visited, int minDist, int i, int j){
        int n=grid.size();
        
        // index out of bounds
        if(i < 0 || i >= n || j < 0 || j >= n)
            return false;
        // already visited cell
        if(visited[i][j])
            return false;

        // mark the curr cell as visited
        visited[i][j] = true;

        // dist of curr cell dips below the 'minDist' allowed
        if(dist[i][j] < minDist)
            return false;
        // reached the destination :)
        if(i == n-1 && j == n-1)
            return true;
        
        // move in down, right, left, up directions
        return 
        dfs(grid, dist, visited, minDist, i+1, j) || 
        dfs(grid, dist, visited, minDist, i, j+1) ||
        dfs(grid, dist, visited, minDist, i, j-1) ||
        dfs(grid, dist, visited, minDist, i-1, j);
    }

public:
    // T.C.=O(n^3), S.C.=O(n^2)
    // Multi-Source BFS + Linear-Search + DFS
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();

        // STEP 1: run Multi-Source BFS() starting with all cells with 1 (thief)
        // thereby calculating the distance of the closest thief for each cell

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1)
                {
                    visited[i][j] = true;
                    q.push({i, j});
                }

        
        multiSourceBFS(grid, dist, visited, q);

        // STEP 2: run DFS() to verify that the cell (n-1, n-1) is reachable from (0, 0)
        // by a path in which each cell has dist[i][j] >= minDist

        int maxVal = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                maxVal = max(maxVal, dist[i][j]);

        for(int minDist = maxVal; minDist > 0; minDist--)
        {
            vector<vector<bool>> visited(n, vector<bool>(n, false));

            if(dfs(grid, dist, visited, minDist, 0, 0))
                return minDist;
        }

        return 0;
    }
};
/*
# grid[i][j]: 0 (empty), 1 (thief)
# dist[i][j]: Manhattan-distance of the closest cell with 1, ie, thief from the curr cell
# Manhattan-distacne between any 2 cells in a n*n grid is in range [0, 2*(n-1)]
# min distacne is when the 2 cells are at the same position
# max distacne is when the 2 cells are at digonally opposite corners
# more precisely, max distance between any 2 cells is the max value found in dist[][]
*/