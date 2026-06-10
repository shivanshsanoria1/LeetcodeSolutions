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
            int c=check(grid);
            if(c==1) // A wins
                return "A";
            else if(c==-1) // B wins
                return "B";
        }
        if(n==9) // no winner after max no. of turns
            return "Draw";
        return "Pending";
    }
    
    int check(vector<vector<int>>& grid)
    {
        for(int i=0; i<3; i++) // check for rows
        {
            int sum=0;
            for(int j=0; j<3; j++)
                sum=sum+grid[i][j];
            if(sum==3) // A wins
                return 1;
            else if(sum==-3) // B wins
                return -1;
        }
        
        for(int j=0; j<3; j++) // check for columns
        {
            int sum=0;
            for(int i=0; i<3; i++)
                sum=sum+grid[i][j];
            if(sum==3) // A wins
                return 1;
            else if(sum==-3) // B wins
                return -1;
        }
        
        int sum;
        sum=grid[0][0]+grid[1][1]+grid[2][2]; // check for left-diagonal
        if(sum==3) // A wins
            return 1;
        else if(sum==-3) // B wins
            return -1;
        
        sum=grid[0][2]+grid[1][1]+grid[2][0]; // check for right-diagonal
        if(sum==3) // A wins
            return 1;
        else if(sum==-3) // B wins
            return -1;
        
        return 0; // no one wins
    }
};