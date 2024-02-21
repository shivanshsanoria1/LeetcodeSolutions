class Solution {
public:
    int solve(vector<vector<int>>& pairs, vector<vector<int>>& dp, int i, int prevPairIdx){
        if(i >= pairs.size())
            return 0;

        if(dp[i][1 + prevPairIdx] != -1)
            return dp[i][1 + prevPairIdx];

        int currStart = pairs[i][0];
        int currEnd = pairs[i][1];
        int prevEnd = prevPairIdx != -1 ? pairs[prevPairIdx][1] : INT_MIN;

        int exclude = solve(pairs, dp, i+1, prevPairIdx);
        int include = (prevEnd < currStart) ? 1 + solve(pairs, dp, i+1, i) : 0;

        dp[i][1 + prevPairIdx] = max(exclude, include);
        return dp[i][1 + prevPairIdx];
    }

    int findLongestChain(vector<vector<int>>& pairs) { // Memoization, T.C.=O(n^2), S.C.=O(n^2)
        sort(pairs.begin(), pairs.end());
        int n=pairs.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(pairs, dp, 0, -1);
    }
};