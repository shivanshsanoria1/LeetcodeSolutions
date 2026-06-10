class Solution {
private:
    typedef pair<int, int> PII;
    typedef vector<int> VI;

public:
    // T.C.=O(??), S.C.=O(m*n)
    // Dijkstra
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();

        // minTime[i][j]: min. time to reach (i, j) from (0, 0)
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        minTime[0][0] = 0;

        // up, down, left, right
        vector<PII> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // {minTime[i][j], i, j}
        priority_queue<VI, vector<VI>, greater<VI>> pq;
        pq.push({minTime[0][0], 0, 0});

        while(!pq.empty())
        {
            int currT = pq.top()[0];
            int currX = pq.top()[1], currY = pq.top()[2];
            pq.pop();

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
                    pq.push({minTime[x][y], x, y});
                }
            }
        }

        return minTime[m-1][n-1];
    }
};