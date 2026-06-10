class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // Multi-Source BFS
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // add all elements of 0th col in queue
        for(int i=0; i<m; i++)
        {
            visited[i][0] = true;
            q.push({i, 0});
        }

        vector<int> dirs = {-1, 0, 1};
        int moves = -1;
        while(!q.empty())
        {
            // max num of moves possible is (n-1)
            if(++moves == n-1)
                break;

            int size = q.size();
            while(size--)
            {
                auto [currX, currY] = q.front();
                q.pop();

                for(int dir: dirs)
                {
                    int x = currX + dir;
                    int y = currY + 1;

                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    
                    if(grid[currX][currY] >= grid[x][y])
                        continue;
                    
                    if(visited[x][y])
                        continue;
                    
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }

        return moves;
    }
};