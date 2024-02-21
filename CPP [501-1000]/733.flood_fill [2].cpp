class Solution {
public:
    typedef pair<int ,int> PI;

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) { // BFS
        int m=image.size(), n=image[0].size();
        int startColor = image[sr][sc];
        vector<PI> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // up, down, left, right
        set<PI> visited;
        queue<PI> q;
        visited.insert({sr, sc});
        q.push({sr, sc});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            image[x][y] = color; // fill the new color in the curr cell
            for(auto dir: dirs)
            {
                int x1 = x + dir.first;
                int y1 = y + dir.second;
                if(x1<0 || x1>=m || y1<0 || y1>=n) // index out of bounds
                    continue;
                // color of the cell is the same as start color and cell is unvisited
                if(image[x1][y1] == startColor && visited.find({x1, y1}) == visited.end())
                {
                    visited.insert({x1, y1});
                    q.push({x1, y1});
                }
            }
        }
        return image;
    }
};