class Solution {
private:
    void bfs(vector<vector<int>>& isWater, vector<vector<int>>& heights, queue<pair<int, int>>& q){
        int m=isWater.size(), n=isWater[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int level = 1;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto [currX, currY] = q.front();
                q.pop();

                for(auto [dx, dy]: dirs)
                {
                    int x = currX + dx;
                    int y = currY + dy;

                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    if(heights[x][y] != -1)
                        continue;

                    heights[x][y] = level;
                    q.push({x, y});
                }
            }

            level++;
        }
    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // Multi-Source-BFS
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(), n=isWater[0].size();

        vector<vector<int>> heights(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(isWater[i][j] == 1)
                {
                    heights[i][j] = 0;
                    q.push({i, j});
                }

        bfs(isWater, heights, q);

        return heights;
    }
};