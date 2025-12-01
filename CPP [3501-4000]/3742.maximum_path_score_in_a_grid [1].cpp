class Solution {
private:
    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost, VEC3D& dp){
        int m = grid.size(), n = grid[0].size();
        // index out of bounds
        if(i>=m || j>=n)
            return -1;
        // update the cost
        if(grid[i][j] > 0)
            cost++;
        // max cost exceeded
        if(cost > k)
            return -1;
        // result already in dp
        if(dp[i][j][cost] != -100)
            return dp[i][j][cost];
        // reached the dest. cell
        if(i == m-1 && j == n-1){
            dp[i][j][cost] = grid[i][j];
            return dp[i][j][cost];
        }
        
        int down = solve(grid, k, i+1, j, cost, dp);
        int right = solve(grid, k, i, j+1, cost, dp);

        // no path leads to dest. cell
        if(max(down, right) == -1){
            dp[i][j][cost] = -1;
            return dp[i][j][cost];
        }

        dp[i][j][cost] = grid[i][j] + max(down, right);
        return dp[i][j][cost];
    }

public:
    // T.C.=O(m*n*k), S.C.=O(m*n*k)
    // DP (3d): Memoization
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        VEC3D dp(m, VEC2D(n, VEC1D(k+1, -100)));

        return solve(grid, k, 0, 0, 0, dp); 
    }
};