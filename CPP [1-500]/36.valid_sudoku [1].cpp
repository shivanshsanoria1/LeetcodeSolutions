class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={false}; //9*9 grid to keep count of rows ; initialized by false
        bool col[9][9]={false}; //9*9 grid to keep count of columns ; initialized by false
        bool box[9][9]={false}; //9*9 grid to keep count of boxes ; initialized by false
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                if(board[i][j] != '.')
                {
                    int pos= board[i][j]-'0'-1; //find vertical position of element in row[][], col[][], box[][]
                    
                    if(row[i][pos]==true) //check row
                        return false;
                    row[i][pos]=true;
                    
                    if(col[j][pos]==true) //check col
                        return false;
                    col[j][pos]=true;
                    
                    int box_index= (i/3)*3 + j/3;
                    if(box[box_index][pos]==true) //check box
                        return false;
                    box[box_index][pos]=true;
                }
        return true;
    }
};
// row[x][y]: y keeps track of element with value (y+1) in xth row in original 9*9 grid
// col[x][y]: y keeps track of element with value (y+1) in xth col in original 9*9 grid
// box[x][y]: y keeps track of element with value (y+1) in xth box in original 9*9 grid