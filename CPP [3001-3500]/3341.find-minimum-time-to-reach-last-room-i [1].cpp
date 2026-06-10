class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(??), S.C.=O(m*n)
    // BFS
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        
        // minTime[i][j]: min. time to reach (i, j) from (0, 0)
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        minTime[0][0] = 0;

        // up, down, left, right
        vector<PII> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<PII> q; // {i, j}
        q.push({0, 0});

        while(!q.empty())
        {
            auto [currX, currY] = q.front();
            q.pop();

            int currT = minTime[currX][currY];

            for(auto [dx, dy]: dirs)
            {
                int x = currX + dx;
                int y = currY + dy;

                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                
                int t = 1 + max(currT, moveTime[x][y]);

                if(t < minTime[x][y])
                {
                    minTime[x][y] = t;
                    q.push({x, y});
                }
            }
        }

        return minTime[m-1][n-1];
    }
};