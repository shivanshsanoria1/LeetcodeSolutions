class Solution {
public:
    int solve(vector<vector<int>>& pairs, vector<vector<int>>& dp, int i, int prevEnd){
        if(i >= pairs.size())
            return 0;

        if(dp[i][1001 + prevEnd] != -1)
            return dp[i][1001 + prevEnd];

        int currStart = pairs[i][0];
        int currEnd = pairs[i][1];

        int exclude = solve(pairs, dp, i+1, prevEnd);
        int include = (prevEnd < currStart) ? 1 + solve(pairs, dp, i+1, currEnd) : 0;
        
        dp[i][1001 + prevEnd] = max(exclude, include);
        return dp[i][1001 + prevEnd];
    }

    int findLongestChain(vector<vector<int>>& pairs) { // Memoization, T.C.=O(n^2), S.C.=O(2002*n)
        sort(pairs.begin(), pairs.end());
        int n=pairs.size();
        vector<vector<int>> dp(n, vector<int>(2002, -1));
        return solve(pairs, dp, 0, -1001);
    }
};