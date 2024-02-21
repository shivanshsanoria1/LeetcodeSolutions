class Solution {
public:
    unordered_set<int> col;
    unordered_set<int> diag1; //left diagonal , (r-c) is const
    unordered_set<int> diag2; //right diagonal , (r+c) is const
    
    void solve(vector<vector<string>>& ans, vector<vector<char>>& board, int n, int r)
    {
        if(r==n) //add curr board to ans
        {
            vector<string> vec;
            for(int i=0; i<n; i++)
            {
                string s="";
                for(int j=0; j<n; j++)
                    s += board[i][j];
                vec.push_back(s);
            }
            ans.push_back(vec);
            return;
        }
        for(int c=0; c<n; c++) //iterate in cols
        {
            if(col.find(c) != col.end()) //c is present in col set
                continue;
            if(diag1.find(r-c) != diag1.end()) //(r-c) is present in diag1 set
                continue;
            if(diag2.find(r+c) != diag2.end()) //(r+c) is present in diag2 set
                continue;
            
            col.insert(c);
            diag1.insert(r-c);
            diag2.insert(r+c);
            board[r][c]='Q'; //place the queen
            
            solve(ans,board,n,r+1); //move to next row
            
            col.erase(c);
            diag1.erase(r-c);
            diag2.erase(r+c);
            board[r][c]='.'; //take out the queen
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n,vector<char>(n,'.')); //n*n board filled with '.'
        solve(ans,board,n,0); //initially row=0
        return ans;
    }
};