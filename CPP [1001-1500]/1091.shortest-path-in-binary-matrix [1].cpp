class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) { // BFS
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) // no path possible
            return -1;
        // north, south, east, west, nortEast, northWest, southEast, southWest
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}, {-1,1}, {-1,-1}, {1,1}, {1,-1}};
        queue<pair<int, int>> q;
        grid[0][0] = -1; // mark the cell {0,0} as visited
        q.push({0, 0});
        int steps = 1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == n-1 && y == n-1) // reached the destination
                    return steps;
                for(auto dir: dirs)
                {
                    int x1 = x + dir.first;
                    int y1 = y + dir.second;
                    if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) // index out of bounds
                        continue;
                    if(grid[x1][y1] != 0) // skip any cell other than unvisited land
                        continue;
                    grid[x1][y1] = -1; // mark the curr cell as visited
                    q.push({x1, y1});
                }
            }
            steps++;
        }
        return -1; // no path found
    }
};
// -1: visited land, 0: unvisited land, 1: water