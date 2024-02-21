class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i >= m || j >= n) // index out of bounds
            return INT_MAX;
        if(i == m-1 && j == n-1) // reached the bottom-right corner
            return grid[i][j];
        int down = solve(grid, i+1, j); // down
        int right = solve(grid, i, j+1); // right
        return grid[i][j] + min(down, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) { // Recursion
        return solve(grid, 0, 0);
    }
};