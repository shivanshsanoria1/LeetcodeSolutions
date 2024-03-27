class Solution {
private:
    void restoreBoard(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] == 'V')
                    board[i][j] = 'X';
    }

public:
    // T.C.=O(m*n), S.C.=O(1)
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        int count = 0;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                // skip the unvisited-battleships
                if(board[i][j] != 'X')
                    continue;

                // mark the curr-battleship as visited
                board[i][j] = 'V';
                
                // check in the same row
                for(int k=j+1; k<n; k++)
                {
                    if(board[i][k] == 'X')
                        board[i][k] = 'V';
                    else
                        break;
                }

                // check in the same col
                for(int k=i+1; k<m; k++)
                {
                    if(board[k][j] == 'X')
                        board[k][j] = 'V';
                    else
                        break;
                }
                
                count++;
            }

        restoreBoard(board); // not-required

        return count;
    }
};
// '.': empty, 'X': unvisited-battleship, 'V': visited-battleship