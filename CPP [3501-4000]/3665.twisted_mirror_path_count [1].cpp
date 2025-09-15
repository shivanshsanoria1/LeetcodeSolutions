class Solution {
private:
    #define MOD int(1e9 + 7)

    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    int solve(vector<vector<int>>& grid, int i, int j, int dir, VEC3D& dp){
        int m = grid.size(), n = grid[0].size();
        // moved out of bounds
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;

        // reached the last cell
        if(dp[i][j][dir] != -1)
            return dp[i][j][dir];
        
        if(i == m-1 && j == n-1)
            return 1;
        
        // cell has a mirror
        if(grid[i][j] == 1){
            // changed direction from down to right
            if(dir == 1){
                dp[i][j][dir] = solve(grid, i, j+1, 2, dp);
                return dp[i][j][dir];
            }
            // changed direction from right to down
            else if(dir == 2){
                dp[i][j][dir] = solve(grid, i+1, j, 1, dp);
                return dp[i][j][dir];
            }
        }

        int down = solve(grid, i+1, j, 1, dp);
        int right = solve(grid, i, j+1, 2, dp);

        dp[i][j][dir] = (down + right) % MOD;
        return dp[i][j][dir];
    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // DP: memoization
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // 3D dp of size m*n*3 filled with -1's
        VEC3D dp(m, VEC2D(n, VEC1D(3, -1)));

        return solve(grid, 0, 0, 0, dp);
    }
};

// dir: 0 (no direction), 1 (down), 2 (right)