class Solution {
public:
    // T.C.=O(8*8), S.C.=O(1)
    int numRookCaptures(vector<vector<char>>& board) {
        int startI = -1, startJ = -1;
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
                if(board[i][j] == 'R')
                {
                    startI = i;
                    startJ = j;
                    break;
                }
        
        int count = 0;

        // up
        for(int i = startI - 1; i>=0; i--)
        {
            if(board[i][startJ] == 'p')
            {
                count++;
                break;
            }
            else if(board[i][startJ] == 'B')
                break;
        }

        // down
        for(int i = startI + 1; i<8; i++)
        {
            if(board[i][startJ] == 'p')
            {
                count++;
                break;
            }
            else if(board[i][startJ] == 'B')
                break;
        }

        // left
        for(int j = startJ - 1; j>=0; j--)
        {
            if(board[startI][j] == 'p')
            {
                count++;
                break;
            }
            else if(board[startI][j] == 'B')
                break;
        }

        // right
        for(int j = startJ + 1; j<8; j++)
        {
            if(board[startI][j] == 'p')
            {
                count++;
                break;
            }
            else if(board[startI][j] == 'B')
                break;
        }

        return count;
    }
};