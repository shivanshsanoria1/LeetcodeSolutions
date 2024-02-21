class Solution {
public:
    void dfs(vector<vector<char>>& board, int m, int n, int i, int j)
    {
        if(i<0 || i>=m || j<0 || j>=n) //index out of bounds
            return;
        if(board[i][j] != 'O') //no further operations on element which are not 'O'
            return;
        board[i][j]='T'; //mark the 'O' as 'T' to show them as visited
        dfs(board,m,n,i-1,j); //up
        dfs(board,m,n,i+1,j); //down
        dfs(board,m,n,i,j-1); //left
        dfs(board,m,n,i,j+1); //right
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int j=0; j<n; j++) //0th row
            dfs(board,m,n,0,j);
        for(int j=0; j<n; j++) //last row
            dfs(board,m,n,m-1,j);
        for(int i=0; i<m; i++) //0th col
            dfs(board,m,n,i,0);
        for(int i=0; i<m; i++) //last col
            dfs(board,m,n,i,n-1);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='T')
                    board[i][j]='O';
            }
    }
};
// 1. for every boundary 'O' make a dfs() call and mark all the connected 'O's as 'T's
// now all the unsurrounded 'O's are marked as 'T's and the surrounded 'O's remains as 'O's
// 2. convert all the 'O's as 'X's and 'T's as 'O's