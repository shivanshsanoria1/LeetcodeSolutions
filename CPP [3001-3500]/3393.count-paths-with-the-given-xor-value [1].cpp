class Solution {
private:
    #define MOD int(1e9 + 7)

    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    int solve(vector<vector<int>>& grid, int k, int i, int j, int x, VEC3D& dp){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        
        x ^= grid[i][j];

        if(dp[i][j][x] != -1)
            return dp[i][j][x];

        if(i == m-1 && j == n-1 && x == k)
            return 1;

        int down = solve(grid, k, i+1, j, x, dp);
        int right = solve(grid, k, i, j+1, x, dp);

        dp[i][j][x] = (down + right) % MOD;
        return dp[i][j][x]; 
    }

public:
    // DP: Memoization
    // T.C.=O(m*n*16), S.C.=O(m*n*16)
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        VEC3D dp(m, VEC2D(n, VEC1D(16, -1)));

        return solve(grid, k, 0, 0, 0, dp);
    }
};

// since grid[i][j] is in range [0, 15], 
// the XOR of all of them is also in range [0, 15]