class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n=moves.size(),row,col;
        vector<vector<int>> grid(3,vector<int> (3,0)); // initialize a 3*3 grid with 0's ; 0 represents empty space
        for(int i=0; i<n; i++)
        {
            row=moves[i][0];
            col=moves[i][1];
            if(i%2==0) // A's turn
                grid[row][col]=1; // fill 1 ; 1 represents 'X'
            else // B's turn
                grid[row][col]=-1; // fill -1 ; -1 represents 'O'
            int c=check(grid,3);
            if(c==1) // A wins
                return "A";
            else if(c==-1) // B wins
                return "B";
        }
        if(n==9) // no winner after max no. of turns
            return "Draw";
        return "Pending";
    }
    
    int check(vector<vector<int>>& grid, int n) // n*n grid is passed
    {
        for(int i=0; i<n; i++) // check for rows
        {
            int sum=0;
            for(int j=0; j<n; j++)
                sum=sum+grid[i][j];
            if(sum==n) // A wins
                return 1;
            else if(sum==-n) // B wins
                return -1;
        }
        
        for(int j=0; j<n; j++) // check for columns
        {
            int sum=0;
            for(int i=0; i<n; i++)
                sum=sum+grid[i][j];
            if(sum==n) // A wins
                return 1;
            else if(sum==-n) // B wins
                return -1;
        }
        
        int sum=0;
        for(int k=0; k<n; k++) // check for left-diagonal
            sum=sum+grid[k][k];
        if(sum==n) // A wins
            return 1;
        else if(sum==-n) // B wins
            return -1;
        
        sum=0;
        for(int k=0; k<n; k++) // check for right-diagonal
            sum=sum+grid[k][n-1-k];
        if(sum==n) // A wins
            return 1;
        else if(sum==-n) // B wins
            return -1;
        
        return 0; // no one wins
    }
};