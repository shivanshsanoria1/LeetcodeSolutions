class Solution {
private:
    #define MOD int(1e9 + 7)

    typedef vector<int> VEC1D;
    typedef vector<vector<int>> VEC2D;
    typedef vector<vector<vector<int>>> VEC3D;

    int solve(VEC3D& dp, int n, int a, int l){
        if(n == 0)
            return 1;
            
        if(dp[n][a][l] != -1)
            return dp[n][a][l];

        // choosing 'P' does not affect 'a' and resets 'l' to 0
        int p_count = solve(dp, n-1, a, 0);
        // choosing 'L' does not affect 'a' and increments 'l' by 1
        int l_count = l+1 < 3 ? solve(dp, n-1, a, l+1) : 0;
        // choosing 'A' incrments 'a' by 1 and resets 'l' to 0
        int a_count = a+1 < 2 ? solve(dp, n-1, a+1, 0) : 0;

        dp[n][a][l] = ((p_count + l_count) % MOD + a_count) % MOD;

        return dp[n][a][l];
    }

public:
    // T.C.=O(6*n), S.C.=O(6*n)
    // DP-Memoization
    int checkRecord(int n) {
        // 3d dp of size (n+1)*2*3 filled with -1's
        VEC3D dp(n+1, VEC2D(2, VEC1D(3, -1)));

        return solve(dp, n, 0, 0);
    }
};
/*
# a: total num of A's chosen in curr string
# l: num of consecutive L'S at the end of curr string
# possible values of 'a' are 0, 1
# possible values of 'l' are 0, 1, 2
*/