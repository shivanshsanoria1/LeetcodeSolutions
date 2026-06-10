class Solution {
public:
    // T.C.=O(m*n), S.C.=O(2*m)
    // DP: Tabulation with Space-Optimization
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // 0 moves for the elemnts in the 0th col
        vector<int> dp_prev(m, 0);
        // curr is empty for the next iteration
        vector<int> dp_curr(m, -1);
        
        vector<int> dirs = {-1, 0, 1};
        int moves = 0;

        for(int j=1; j<n; j++)
        {
            for(int i=0; i<m; i++)
                for(int dir: dirs)
                {
                    int x = i + dir;
                    int y = j - 1;

                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    
                    if(grid[x][y] >= grid[i][j])
                        continue;

                    if(dp_prev[x] == -1)
                        continue;
                    
                    dp_curr[i] = max(dp_curr[i], 1 + dp_prev[x]);

                    moves = max(moves, dp_curr[i]);
                }
            
            // update prev
            dp_prev = dp_curr;
            // reset curr
            fill(dp_curr.begin(), dp_curr.end(), -1);
        }

        return moves;
    }
};