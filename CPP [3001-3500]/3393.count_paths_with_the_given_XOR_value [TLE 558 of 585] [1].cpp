class Solution {
private:
    #define MOD int(1e9 + 7)

    int solve(vector<vector<int>>& grid, int k, int i, int j, int x){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        
        x ^= grid[i][j];

        if(i == m-1 && j == n-1 && x == k)
            return 1;

        int down = solve(grid, k, i+1, j, x);
        int right = solve(grid, k, i, j+1, x);

        return (down + right) % MOD;
    }

public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        return solve(grid, k, 0, 0, 0);
    }
};