class Solution {
private:
    void bfs(vector<vector<int>>& land, vector<vector<int>>& ans, int startX, int startY){
        int m=land.size(), n=land[0].size();
        int lastX = startX, lastY = startY;
        // up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;

        land[startX][startY] =  -1;
        q.push({startX, startY});
        while(!q.empty())
        {
            auto [currX, currY] = q.front();
            q.pop();
            lastX = currX;
            lastY = currY;
            for(auto [dx, dy]: dirs)
            {
                int x = currX + dx;
                int y = currY + dy;
                // index out of bounds
                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                // not an unvisited-land
                if(land[x][y] != 1)
                    continue;
                // mark the curr land as visited
                land[x][y] = -1;
                q.push({x, y});
            }
        }
        ans.push_back({startX, startY, lastX, lastY});
    }

    void restoreGrid(vector<vector<int>>& land){
        int m=land.size(), n=land[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(land[i][j] == -1)
                    land[i][j] = 1;
    }

public:
    // T.C.=O(m*n), S.C.=O(1)
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size(), n=land[0].size();
        vector<vector<int>> ans;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(land[i][j] == 1)
                    bfs(land, ans, i, j);

        restoreGrid(land); // not-required
        return ans;
    }
};

// 0: forested, 1: unvisited-farmland, -1: visited-farmland