class Solution {
private:
    typedef vector<int> VI;

public:
    // T.C.=O(m*n*log(m*n)), S.C.=O(m*n)
    // similar to Dijkstra
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(); int n = moveTime[0].size();

        // minTime[i][j]: min. time to reach (i, j) from (0, 0)
        vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
        minTime[0][0] = 0;

        // up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // min-heap; {minTime, i, j, parity}
        priority_queue<VI, vector<VI>, greater<VI>> pq;
        pq.push({0, 0, 0, 2});

        while(!pq.empty())
        {
            int currT = pq.top()[0];
            int currX = pq.top()[1];
            int currY = pq.top()[2];
            int currParity = pq.top()[3];
            pq.pop();

            for(auto [dx, dy]: dirs)
            {
                int x = currX + dx;
                int y = currY + dy;

                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                
                int flippedParity = currParity == 1 ? 2 : 1;
                int t = flippedParity + max(currT, moveTime[x][y]);

                // new min. time found to reach the cell (x, y)
                if(t < minTime[x][y])
                {
                    minTime[x][y] = t;
                    pq.push({t, x, y, flippedParity});
                }
            }
        }

        return minTime[m-1][n-1];
    }
};