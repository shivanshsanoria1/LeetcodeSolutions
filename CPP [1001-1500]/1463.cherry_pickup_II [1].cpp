class Solution {
private:
    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    int solve(vector<vector<int>>& grid, VEC3D& dp, int r, int c1, int c2){
        int m=grid.size(), n=grid[0].size();
        // col index out of bounds
        if(min(c1, c2) < 0 || max(c1, c2) >= n)
            return 0;
        // result already present in dp
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        // reached the last row
        if(r == m-1)
            return grid[r][c1] + grid[r][c2];
        // col directions for the next recursive calls
        vector<int> dirs = {-1, 0, 1};

        int res = 0;
        for(int dy1: dirs)
            for(int dy2: dirs)
            {
                // col coordinates for the next row 
                int y1 = c1 + dy1;
                int y2 = c2 + dy2;
                // keeping the col different for both robots
                // ensures maximizing the result
                if(y1 == y2)
                    continue;
                res = max(res, solve(grid, dp, r+1, y1, y2));
            }
        // store the curr result in dp before returning
        dp[r][c1][c2] = res + grid[r][c1] + grid[r][c2];
        return dp[r][c1][c2]; 
    }

public:
    // T.C.=O(m*n^2), S.C.=O(m*n^2), Memoization
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        // dp of size m*n*n filled with -1's
        VEC3D dp(m, VEC2D(n, VEC1D(n, -1)));
        return solve(grid, dp, 0, 0, n-1);
    }
};