class Solution {
private:
    int solve(vector<vector<int>>& grid, int i, int prevCol){
        int n=grid.size();

        if(i >= n)
            return 0;
        
        int minSum = INT_MAX;

        for(int j=0; j<n; j++)
            if(j != prevCol)
                minSum = min(minSum, grid[i][j] + solve(grid, i+1, j));

        return minSum;
    }

public:
    // T.C.=O(n^n)
    // Recursion
    int minFallingPathSum(vector<vector<int>>& grid) {
        return solve(grid, 0, -1);
    }
};