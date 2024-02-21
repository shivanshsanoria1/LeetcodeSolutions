class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int area = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) // block does not exist
                    continue;
                area += 2 + 4 * grid[i][j]; // total area of a block
                // remove the common area between 2 blocks
                if(i > 0) 
                    area -= 2 * min(grid[i][j], grid[i-1][j]);
                if(j > 0)
                    area -= 2 * min(grid[i][j], grid[i][j-1]);
            }
        }
        return area;
    }
};