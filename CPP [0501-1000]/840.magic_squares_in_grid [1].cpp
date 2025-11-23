class Solution {
private:
    // returns true if the 3*3 square centered at {x, y} is a Magic square
    bool isMagicSquare(vector<vector<int>>& grid, int x, int y){
        vector<bool> found(10, false);
        for(int i=x-1; i<=x+1; i++)
            for(int j=y-1; j<=y+1; j++)
            {
                if(grid[i][j] < 1 || grid[i][j] > 9)
                    return false;
                found[grid[i][j]] = true;
            }
        
        for(int i=1; i<=9; i++)
            if(!found[i])
                return false;

        int row1 = grid[x-1][y-1] + grid[x-1][y] + grid[x-1][y+1];
        int row2 = grid[x][y-1] + grid[x][y] + grid[x][y+1];
        int row3 = grid[x+1][y-1] + grid[x+1][y] + grid[x+1][y+1];

        if(!(row1 == 15 && row2 == 15 && row3 == 15))
            return false;

        int col1 = grid[x-1][y-1] + grid[x][y-1] + grid[x+1][y-1];
        int col2 = grid[x-1][y] + grid[x][y] + grid[x+1][y];
        int col3 = grid[x-1][y+1] + grid[x][y+1] + grid[x+1][y+1];

        if(!(col1 == 15 && col2 == 15 && col3 == 15))
            return false;

        int dia1 = grid[x-1][y-1] + grid[x][y] + grid[x+1][y+1];
        int dia2 = grid[x-1][y+1] + grid[x][y] + grid[x+1][y-1];

        if(!(dia1 == 15 && dia2 == 15))
            return false;

        return true;
    }

public:
    // T.C.=O(m*n*9), S.C.=O(9)
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int count = 0;
        for(int i=1; i<m-1; i++)
            for(int j=1; j<n-1; j++)
                if(isMagicSquare(grid, i, j))
                    count++;
        
        return count;
    }
};
/*
# a Magic-square contains the nums in range [1, 9] once
  so sum of all nums in it is 
  = 1 + 2 + 3 + ... + 9
  = (9*10)/2
  = 45
# since each row must have the same sum so
  the sum of each row must be 45/3 = 15
# similarly, sum of each col must be 15
  and the sum of each diagonal must be 15
*/