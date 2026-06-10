class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // DP: Tabulation
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // 0 moves for the elemnts in the 0th col
        for(int i=0; i<m; i++)
            dp[i][0] = 0;
        
        vector<int> dirs = {-1, 0, 1};
        int moves = 0;

        for(int j=1; j<n; j++)
            for(int i=0; i<m; i++)
                for(int dir: dirs)
                {
                    int x = i + dir;
                    int y = j - 1;

                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    
                    if(grid[x][y] >= grid[i][j])
                        continue;

                    if(dp[x][y] == -1)
                        continue;
                    
                    dp[i][j] = max(dp[i][j], 1 + dp[x][y]);
                    
                    moves = max(moves, dp[i][j]);
                }

        return moves;
    }
};