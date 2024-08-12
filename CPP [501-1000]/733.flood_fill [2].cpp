class Solution {
private:
    typedef pair<int, int> PII;

    void bfs(vector<vector<int>>& image, int newColor, int startX, int startY){
        int m=image.size(), n=image[0].size();
        int startColor = image[startX][startY];
        // up, down, left, right
        vector<PII> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}; 
        queue<PII> q;
        image[startX][startY] = newColor;
        q.push({startX, startY});

        while(!q.empty())
        {
            auto [currX, currY] = q.front();
            q.pop();

            for(auto [dx, dy]: dirs)
            {
                int x = currX + dx;
                int y = currY + dy;

                if(x<0 || x>=m || y<0 || y>=n)
                    continue;
                if(image[x][y] != startColor)
                    continue;
                if(image[x][y] == newColor)
                    continue;

                image[x][y] = newColor;
                q.push({x, y});
            }
        }
    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bfs(image, color, sr, sc);
        return image;
    }
};