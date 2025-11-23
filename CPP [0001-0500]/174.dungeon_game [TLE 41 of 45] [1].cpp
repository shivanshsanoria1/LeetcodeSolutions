class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i >= m || j >= n) // index out of bounds
            return INT_MIN;
        if(i == m-1 && j == n-1) // reached the bottom-right corner
            return grid[i][j] >= 0 ? 0 : grid[i][j];
        int down = solve(grid, i+1, j); // down
        int right = solve(grid, i, j+1); // right
        int result = grid[i][j] + max(down, right);
        return result >= 0 ? 0 : result;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) { // Recursion
        return 1 + abs(solve(dungeon, 0, 0));
    }
};
// if the result at curr cell is +ive, reduce it to 0
// if it is -ive then just return it