class Solution {
private:
    // returns true if the 2x2 square with top-left corner at (i, j)
    // has atmost 1 black or atmost 1 white cell
    bool check2x2Square(vector<vector<char>>& grid, int i, int j){
        int black = 0, white = 0;

        if(grid[i][j] == 'B')
            black++;
        else
            white++;

        if(grid[i][j+1] == 'B')
            black++;
        else
            white++;
        
        if(grid[i+1][j] == 'B')
            black++;
        else
            white++;

        if(grid[i+1][j+1] == 'B')
            black++;
        else
            white++;
        
        return black <= 1 || white <= 1;
    }

public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        return check2x2Square(grid, 0, 0) || check2x2Square(grid, 0, 1) || check2x2Square(grid, 1, 0) || check2x2Square(grid, 1, 1);
    }
};