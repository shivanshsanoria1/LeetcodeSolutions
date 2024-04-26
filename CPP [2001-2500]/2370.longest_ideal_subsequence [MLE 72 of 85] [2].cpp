class Solution {
private:
    int solve(string& s, int k, int prevIdx, int i, vector<vector<int>>& dp){
        if(i >= s.length())
            return 0;
        
        if(dp[i][prevIdx + 1] != -1)
            return dp[i][prevIdx + 1];

        int exclude = solve(s, k, prevIdx, i+1, dp);

        int include = (prevIdx == -1 || abs(s[prevIdx] - s[i]) <= k) ? solve(s, k, i, i+1, dp) : -1;
        
        dp[i][prevIdx + 1] = include >= exclude ? 1 + include : exclude;
        return dp[i][prevIdx + 1]; 
    }

public:
    // T.C.=O(n^2), S.C.=O(n^2)
    // Memoization
    int longestIdealString(string s, int k) {
        int n=s.length();
        // dp fo size n*(n+1) filled with -1's
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(s, k, -1, 0, dp);
    }
};
// prevIdx: index of the last char included in the ideal subsequence
// [prevIdx + 1] is used in dp since prevIdx is -1 based instead of 0 based