class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q){
        int n=grid.size();
        // up, down, left, right
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            level++;
            while(size--)
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
                    if(grid[x1][y1] == 0) // unvisited water
                    {
                        grid[x1][y1] = -1;
                        q.push({x1, y1});
                    }
                }
            }
        }
        return level;
    }

    void resetGrid(vector<vector<int>>& grid){
        int n=grid.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == -1)
                    grid[i][j] = 0;
    }

    int maxDistance(vector<vector<int>>& grid) { // Multisource-BFS, T.C.=O(n^2), S.C.=O(n^2)
        int n=grid.size();
        queue<pair<int, int>> q;
        int landCount = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1) // push the lands in the queue
                {
                    q.push({i, j});
                    landCount++;
                }
        int ans = bfs(grid, q);
        resetGrid(grid); // [Not required]
        return landCount == n*n ? -1 : ans - 1;
    }
};
/*
# -1: visited water, 0: unvisited water, 1: land
# landCount == n*n means all cells are land, ie, no water, so return -1
# landCount == 0 means all cells are water, ie, no land, so return -1 [already handled by bfs()]
*/