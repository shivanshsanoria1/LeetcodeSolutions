class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int m = grid.size(), n = grid[0].size();
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        vector<int> dirs = {-1, 0, 1};
        int res = 0;

        for(int dir: dirs)
        {
            int x = i + dir;
            int y = j + 1;

            if(x < 0 || x >= m || y < 0 || y >= n)
                continue;
            
            if(grid[i][j] >= grid[x][y])
                continue;

            res = max(res, 1 + solve(grid, x, y, dp));
        }

        dp[i][j] = res;
        return dp[i][j]; 
    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // DP: Memoization
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int moves = 0;

        for(int i=0; i<m; i++)
            moves = max(moves, solve(grid, i, 0, dp));

        return moves;
    }
};