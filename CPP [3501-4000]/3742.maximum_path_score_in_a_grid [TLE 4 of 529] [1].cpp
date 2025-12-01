class Solution {
private:
    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost){
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
        // reached the dest. cell
        if(i == m-1 && j == n-1)
            return grid[i][j];
        
        int down = solve(grid, k, i+1, j, cost);
        int right = solve(grid, k, i, j+1, cost);

        // no path leads to dest. cell
        if(max(down, right) == -1)
            return -1;

        return grid[i][j] + max(down, right);
    }

public:
    // T.C.=O(), S.C.=O()
    int maxPathScore(vector<vector<int>>& grid, int k) {
        return solve(grid, k, 0, 0, 0); 
    }
};