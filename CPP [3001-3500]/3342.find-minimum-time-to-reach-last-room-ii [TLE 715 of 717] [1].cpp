class Solution {
public:
    // T.C.=O(??), S.C.=O(m*n)
    // BFS
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(); int n = moveTime[0].size();

        // minTime[i][j]: min. time to reach (i, j) from (0, 0)
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        minTime[0][0] = 0;

        // up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<vector<int>> q; // {i, j, parity}
        q.push({0, 0, 2});

        while(!q.empty())
        {
            int currX = q.front()[0];
            int currY = q.front()[1];
            int currParity = q.front()[2];
            q.pop();

            int currT = minTime[currX][currY];

            for(auto [dx, dy]: dirs)
            {
                int x = currX + dx;
                int y = currY + dy;

                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                
                int flippedParity = currParity == 1 ? 2 : 1;
                int t = flippedParity + max(currT, moveTime[x][y]);

                if(t < minTime[x][y])
                {
                    minTime[x][y] = t;
                    q.push({x, y, flippedParity});
                }
            }
        }

        return minTime[m-1][n-1];
    }
};