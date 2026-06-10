class Solution {
private:
    #define MOD int(1e9 + 7)

    int solve(vector<vector<int>>& dp, int k, int n, int target){
        // solution found if both n and target are exhausted
        if(n == 0 && target == 0)
            return 1;
        // no solution possible if any one of n or target become non +ive
        if(n <= 0 || target <= 0)
            return 0;

        // solution already exists in dp
        if(dp[n][target] != -1)
            return dp[n][target];

        int ways = 0;
        for(int i=1; i<=k; i++)
            ways = (ways + solve(dp, k, n-1, target - i)) % MOD;
        
        // store the solution in dp before returning it
        dp[n][target] = ways;
        return dp[n][target];
    }

public:
    // T.C.=O(n*target*k), S.C.=O(n*target), Memoization
    int numRollsToTarget(int n, int k, int target) {
        if(target < n || target > n*k)
            return 0;

        // dp of size (n + 1)*(target + 1) filled with -1's
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(dp, k, n, target);
    }
    /*
    # target value is possible only if it lies in the range [n*1, n*k]
    # dp[i][j]: num of ways to make target j using i dices
    */
};