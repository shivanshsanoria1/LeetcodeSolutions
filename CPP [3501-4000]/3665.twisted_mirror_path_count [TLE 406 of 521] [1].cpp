class Solution {
private:
    #define MOD int(1e9 + 7)

    int solve(vector<vector<int>>& grid, int i, int j, char dir){
        int m = grid.size(), n = grid[0].size();
        // moved out of bounds
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        
        // reached the last cell
        if(i == m-1 && j == n-1)
            return 1;
        
        // cell has a mirror
        if(grid[i][j] == 1){
            // changed direction from down to right
            if(dir == 'd')
                return solve(grid, i, j+1, 'r');
            // changed direction from right to down
            else if(dir == 'r')
                return solve(grid, i+1, j, 'd');
        }

        // explore both down and right directions
        int down = solve(grid, i+1, j, 'd');
        int right = solve(grid, i, j+1, 'r');

        return (down + right) % MOD;
    }

public:
    // Recursion
    int uniquePaths(vector<vector<int>>& grid) {
        // initially there is no direction
        // that the robot was following previously
        return solve(grid, 0, 0, 'o');
    }
};