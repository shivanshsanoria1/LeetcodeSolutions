class Solution {
private:
    #define MOD int(1e9 + 7)

    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    int dfs(int m, int n, VEC3D &dp, int move, int i, int j){
        // max moves reached
        if(move < 0)
            return 0;
        // index out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        // solution already in dp
        if(dp[i][j][move] != -1)
            return dp[i][j][move];

        int up = dfs(m, n, dp, move - 1, i-1, j);
        int down = dfs(m, n, dp, move - 1, i+1, j);
        int left = dfs(m, n, dp, move - 1, i, j-1);
        int right = dfs(m, n, dp, move - 1, i, j+1);

        // store the soltion in dp before returning
        dp[i][j][move] = ((up + down) % MOD + (left + right) % MOD) % MOD;
        return dp[i][j][move];
    }

public:
    // T.C.=O(m*n*maxMove), S.C.=O(m*n*maxMove), Memoization
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // dp of size m*n*(maxMove + 1) filled with -1's
        VEC3D dp(m, VEC2D(n, VEC1D(maxMove + 1, -1)));
        return dfs(m, n, dp, maxMove, startRow, startColumn);
    }
};