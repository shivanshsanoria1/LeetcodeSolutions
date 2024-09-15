class Solution {
private:
    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    bool solve(vector<vector<int>>& grid, int health, int i, int j, vector<vector<bool>>& visited, VEC3D& dp){
        int m=grid.size(), n=grid[0].size();

        if(i<0 || i>=m || j<0 || j>=n)
            return false;

        if(visited[i][j])
            return false;

        if(grid[i][j] == 1)
            health--;
        
        if(health <= 0)
            return false;

        if(dp[i][j][health] != -1)
            return dp[i][j][health];

        visited[i][j] = true;

        if(i == m-1 && j == n-1)
        {
            dp[i][j][health] = 1;
            return dp[i][j][health];
        }

        bool isFound = 
        solve(grid, health, i-1, j, visited, dp) ||
        solve(grid, health, i+1, j, visited, dp) ||
        solve(grid, health, i, j-1, visited, dp) ||
        solve(grid, health, i, j+1, visited, dp);

        visited[i][j] = false;
        
        dp[i][j][health] = isFound;
        return dp[i][j][health]; 
    }

public:
    // T.C.=O(m*n*health), S.C.=O(m*n*health)
    // DP: Memoization
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        VEC3D dp(m, VEC2D(n, VEC1D(health + 1, -1)));

        return solve(grid, health, 0, 0, visited, dp);
    }
};