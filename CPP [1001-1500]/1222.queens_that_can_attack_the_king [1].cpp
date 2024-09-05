class Solution {
public:
    // T.C.=O(8*8), S.C.=O(8*8)
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> hasQueen(8, vector<bool>(8, false));
        for(vector<int>& queen: queens)
        {
            int i = queen[0];
            int j = queen[1];
            hasQueen[i][j] = true;
        }

        // north, south, east, west, 
        // north-east, north-west, south-east, south-west
        vector<pair<int, int>> dirs = 
        {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}, 
            {1, -1}, {-1, -1}, {1, 1}, {-1, 1}
        };

        vector<vector<int>> attackingQueens;
        for(auto [di, dj]: dirs)
            for(int i = king[0] + di, j = king[1] + dj; i>=0 && i<8 && j>=0 && j<8; i += di, j += dj)
                if(hasQueen[i][j])
                {
                    attackingQueens.push_back({i, j});
                    break;
                }

        return attackingQueens;
    }
};

// a Queen can move in any of the 8 drections:
// north, south, east, west, north-east, north-west, south-east, south-west;
// any num of steps until it reaches another piece or the edge of the board