class Solution {
public:
    bool checkRow(vector<vector<char>>& board, int r)
    {
        bool row[10]={false}; //to keep track of elements present in the row 'r'
        for(int j=0; j<9; j++)
        {
            if(board[r][j] == '.')
                continue;
            int curr= board[r][j]-'0';
            if(row[curr] == true) //'curr' is repeated in the current row
                return false;
            row[curr]= true; //mark 'curr' as present
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>>& board, int c)
    {
        bool col[10]={false}; //to keep track of elements present in the col 'c'
        for(int i=0; i<9; i++)
        {
            if(board[i][c] == '.')
                continue;
            int curr= board[i][c]-'0';
            if(col[curr] == true) //'curr' is repeated in the current col
                return false;
            col[curr]= true; //mark 'curr' as present
        }
        return true;
    }
    
    bool checkBox(vector<vector<char>>& board, int r, int c)
    {
        bool box[10]={false}; //to keep track of elements present in the box formed by 'r','c'
        for(int i=r; i<r+3; i++)
            for(int j=c; j<c+3; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int curr= board[i][j]-'0'; 
                if(box[curr] == true) //'curr' is repeated in the current box
                    return false;
                box[curr]= true; //mark 'curr' as present
            }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++)
            if(checkRow(board,i)==false)
                return false;
        for(int j=0; j<9; j++)
            if(checkCol(board,j)==false)
                return false;
        for(int i=0; i<9; i=i+3)
            for(int j=0; j<9; j=j+3)
                if(checkBox(board,i,j)==false)
                    return false;
        return true; 
    }
};