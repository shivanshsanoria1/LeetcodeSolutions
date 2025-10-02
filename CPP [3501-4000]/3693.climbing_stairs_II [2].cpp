class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // DP: Tabulation with Space-optimization 1-D
    int climbStairs(int n, vector<int>& costs) {
        int curr = 0; // dp[i]
        int prev1 = 0; // dp[i-1]
        int prev2 = -1; // dp[i-2]
        int prev3 = -1; // dp[i-3]

        for(int i=1; i<=n; i++){
            const int INF = int(1e9);

            int cost1 = prev1 + 1;
            int cost2 = prev2 != -1 ? prev2 + 4 : INF;
            int cost3 = prev3 != -1 ? prev3 + 9 : INF;

            curr = costs[i-1] + min(cost3, min(cost2, cost1));

            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

// dp[i] is mapped with costs[i-1] since costs[] is 1-indexed