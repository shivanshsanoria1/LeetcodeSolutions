class Solution {
private:
    int solve(string& s, int k, char prevChar, int i, vector<vector<int>>& dp){
        if(i >= s.length())
            return 0;
        
        if(dp[i][prevChar - 'a'] != -1)
            return dp[i][prevChar - 'a'];

        int exclude = solve(s, k, prevChar, i+1, dp);

        int include = (prevChar == '{' || abs(prevChar - s[i]) <= k) ? solve(s, k, s[i], i+1, dp) : -1;
        
        dp[i][prevChar - 'a'] = include >= exclude ? 1 + include : exclude;
        return dp[i][prevChar - 'a']; 
    }

public:
    // T.C.=O(n*27), S.C.=O(n*27)
    // DP-Memoization
    int longestIdealString(string s, int k) {
        int n=s.length();
        // dp of size n*27 filled with -1's
        vector<vector<int>> dp(n, vector<int>(27, -1));
        
        return solve(s, k, '{', 0, dp);
    }
};
// '{': prev char does not exist
// '{' is chosen as its ASCII value is 1 more than that of 'z' 