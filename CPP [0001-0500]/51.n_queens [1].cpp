class Solution {
public:
    bool isValid(vector<string>& board, int n, int r, int c) //returns true if (r,c) is valid position in board
    {
        for(int i=r; i>=0; i--) //check col
            if(board[i][c]=='Q')
                return false;
        for(int i=r,j=c; i>=0 && j>=0; i--,j--) //check left diagonal
            if(board[i][j]=='Q')
                return false;
        for(int i=r,j=c; i>=0 && j<n; i--,j++) //check right diagonal
            if(board[i][j]=='Q')
                return false;
        return true;
    }
    
    void solve(vector<vector<string>>& ans, vector<string>& board, int n, int r)
    {
        if(r==n) //add curr board to ans
        {
            ans.push_back(board);
            return;
        }
        for(int c=0; c<n; c++) //iterate in cols
            if(isValid(board,n,r,c)) //(r,c) is valid board position
            {
                board[r][c]='Q'; //place the queen
                solve(ans,board,n,r+1); //move to next row
                board[r][c]='.'; //take out the queen
            }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.')); //n*n board filled with '.'
        solve(ans,board,n,0); //initially row=0
        return ans;
    }
};