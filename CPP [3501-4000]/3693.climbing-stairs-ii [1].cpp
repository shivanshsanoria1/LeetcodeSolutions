class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // DP: Tabulation 1-D
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; i++)
            dp[i] = costs[i-1];

        for(int i=1; i<=n; i++){
            const int INF = int(1e9);
            
            int cost1 = dp[i-1] + 1;
            int cost2 = i-2 >= 0 ? dp[i-2] + 4 : INF;
            int cost3 = i-3 >= 0 ? dp[i-3] + 9 : INF;

            dp[i] += min(cost3, min(cost2, cost1));
        }

        return dp[n];
    }
};

// dp[i] is mapped with costs[i-1] since costs[] is 1-indexed