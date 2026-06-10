class Solution {
public:
    // T.C.=O(row*col), S.C.=O(1)
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size(), col=grid[0].size();
        int perimeter = 0;

        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                // skip the water cells
                if(grid[i][j] == 0)
                    continue;

                int count = 4;
                
                if(i-1 >= 0 && grid[i-1][j] == 1) // up
                    count--;
                if(i+1 < row && grid[i+1][j] == 1) // down
                    count--;
                if(j-1 >= 0 && grid[i][j-1] == 1) // left
                    count--;
                if(j+1 < col && grid[i][j+1] == 1) // right
                    count--;
                    
                perimeter += count;
            }

        return perimeter;
    }
};
/*
# 1: land, 0: water
# for each land cell, check the 4-directional neighbours, 
  if it is a land then don't include that edge in the perimeter of the island
*/