class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;
        // up, down, left, right
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) // block does not exist
                    continue;
                area += 2; // top and bottom area
                for(auto dir: dirs)
                {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    // neighbour index out of bounds, ie, curr block has this side exposed
                    if(x < 0 || x >= n || y < 0 || y >= n) 
                        area += grid[i][j];
                    // curr block is taller than its neighbour, so include thier diff in heights in the area
                    else if(grid[i][j] > grid[x][y])
                        area += grid[i][j] - grid[x][y];
                }
            }
        }
        return area;
    }
};