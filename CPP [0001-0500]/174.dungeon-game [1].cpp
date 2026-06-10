class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i >= m || j >= n) // index out of bounds
            return INT_MIN;
        if(dp[i][j] != -1) // result found in dp
            return dp[i][j];
        if(i == m-1 && j == n-1) // reached the bottom-right corner
        {
            dp[i][j] = grid[i][j] >= 0 ? 0 : grid[i][j];
            return dp[i][j];
        }
        int down = solve(grid, dp, i+1, j); // down
        int right = solve(grid, dp, i, j+1); // right
        int result = grid[i][j] + max(down, right);
        dp[i][j] = result >= 0 ? 0 : result;
        return dp[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) { // Memoization, T.C.=O(m*n), S.C.=O(m*n)
        int m=dungeon.size(), n=dungeon[0].size();
        vector<vector<int>> dp(m, vector(n, -1));
        return 1 + abs(solve(dungeon, dp, 0, 0));
    }
};
// if the result at curr cell is +ive, reduce it to 0
// if it is -ive then just return it