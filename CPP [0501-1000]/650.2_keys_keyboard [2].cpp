class Solution {
private:
    #define INF int(1e9)

    int solve(int curr, int prev, int n, vector<vector<int>>& dp){
        if(curr > n)
            return INF;

        if(curr == n)
            return 0;

        if(dp[curr][prev] != -1)
            return dp[curr][prev];
        
        int paste = prev > 0 ? 1 + solve(curr + prev, prev, n, dp) : INF;
        int copyPaste = 2 + solve(curr*2, curr, n, dp);

        dp[curr][prev] = min(paste, copyPaste);
        return dp[curr][prev];
    }

public:
    // T.C.=O(n^2), S.C.=O(n^2)
    // DP: Memoization
    int minSteps(int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, 0, n, dp);
    }
};
// curr: length of curr string
// prev: length of previously copied string