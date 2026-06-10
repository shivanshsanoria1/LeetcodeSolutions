class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int j, int prev){
        int m = grid.size(), n = grid[0].size();

        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        
        if(grid[i][j] <= prev)
            return 0;
        
        int northEast = solve(grid, i-1, j+1, grid[i][j]);
        int east = solve(grid, i, j+1, grid[i][j]);
        int southEast = solve(grid, i+1, j+1, grid[i][j]);

        return 1 + max(east, max(northEast, southEast));
    }

public:
    // T.C.=O(3^n), S.C.=O(n)
    // Recursion
    int maxMoves(vector<vector<int>>& grid) {
        int moves = 0;
        for(int i=0; i<grid.size(); i++)
            moves = max(moves, solve(grid, i, 0, -1) - 1);

        return moves;
    }
};