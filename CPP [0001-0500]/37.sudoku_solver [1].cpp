class Solution {
public:
    bool isValidPos(vector<vector<char>>& board, int r, int c, char ch)
    {
        for(int i=0; i<9; i++)
        {
            if(board[r][i] == ch) //check row
                return false;
            if(board[i][c] == ch) //check col
                return false;
            int x = (r/3)*3 + i/3;
            int y = (c/3)*3 + i%3;
            if(board[x][y] == ch) //check for box
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                if(board[i][j]=='.') //empty cell found
                {
                    for(char ch='1'; ch<='9'; ch++)
                        if(isValidPos(board,i,j,ch)==true)
                        {
                            board[i][j]=ch; //fill the current cell with valid element
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j]='.'; //make the current cell empty
                        }
                    return false;
                }
        return true; //all the cells are filled with valid elements
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};