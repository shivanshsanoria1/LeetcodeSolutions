class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int m, int n, int index) //DFS like algo.
    {
        if(index==word.size()) //word found
            return true;
        if(i<0 || j<0 || i>=m || j>=n) //out of bounds
            return false;
        if(board[i][j]!=word[index]) //wrong character found
            return false;
        char ch=board[i][j]; //save the curr element in ch
        board[i][j]='*'; //mark the curr element as visited
        bool up=solve(board,word,i-1,j,m,n,index+1);
        bool down=solve(board,word,i+1,j,m,n,index+1);
        bool left=solve(board,word,i,j-1,m,n,index+1);
        bool right=solve(board,word,i,j+1,m,n,index+1);
        board[i][j]=ch; //restore the curr element
        return  up || down|| left || right;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(solve(board,word,i,j,m,n,0)==true)
                    return true;
        return false;
    }
};