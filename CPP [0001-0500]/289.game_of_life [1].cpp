class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) { // T.C.=O(m*n) , S.C.=O(m*n)
        int m=board.size(), n=board[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0)); // vector of size m*n with 0's filled
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int alive=neighboursAlive(board,i,j,m,n);
                if(board[i][j]==1) // curr. cell is alive
                    if(alive<2 || alive>3)
                        ans[i][j]=0;
                    else
                        ans[i][j]=1;
                else // curr. cell is dead
                    if(alive==3)
                        ans[i][j]=1;
                    else
                        ans[i][j]=0;
            }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                board[i][j]=ans[i][j];
    }
    
    int neighboursAlive(vector<vector<int>>& board, int i, int j, int m, int n)
    {
        int alive=0;
        if(i-1>=0) // up
        {
            if(j-1>=0 && board[i-1][j-1]==1) // left
                alive++;
            if(board[i-1][j]==1) // mid
                alive++;
            if(j+1<n && board[i-1][j+1]==1) // right
                alive++;
        }
        if(j-1>=0 && board[i][j-1]==1) // left
                alive++;
        if(j+1<n && board[i][j+1]==1) // right
                alive++;
        if(i+1<m) // down
        {
            if(j-1>=0 && board[i+1][j-1]==1) // left
                alive++;
            if(board[i+1][j]==1) // mid
                alive++;
            if(j+1<n && board[i+1][j+1]==1) // right
                alive++;
        }
        return alive;
    }
};