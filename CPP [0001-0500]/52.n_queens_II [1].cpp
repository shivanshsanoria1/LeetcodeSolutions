class Solution {
public:
    bool isValid(vector<vector<char>>& board, int n, int r, int c) //returns true if (r,c) is valid position in board
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
    
    int solve(vector<vector<char>>& board, int n, int r)
    {
        if(r==n) //ans found
            return 1;
        int sol=0; //solutions found
        for(int c=0; c<n; c++) //iterate in cols
            if(isValid(board,n,r,c)) //(r,c) is valid board position
            {
                board[r][c]='Q'; //place the queen
                sol += solve(board,n,r+1); //move to next row
                board[r][c]='.'; //take out the queen
            }
        return sol;
    }
    
    int totalNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.')); //n*n board filled with '.'
        return solve(board,n,0); //initially row=0
    }
};