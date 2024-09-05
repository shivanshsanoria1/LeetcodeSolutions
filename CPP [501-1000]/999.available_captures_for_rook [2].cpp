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
        
        vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        int count = 0;

        for(auto [di, dj]: dirs)
            for(int i = startI, j = startJ; i>=0 && i<8 && j>=0 && j<8; i += di, j += dj)
            {
                if(board[i][j] == 'p')
                {
                    count++;
                    break;
                }
                else if(board[i][j] == 'B')
                    break;
            }

        return count;
    }
};