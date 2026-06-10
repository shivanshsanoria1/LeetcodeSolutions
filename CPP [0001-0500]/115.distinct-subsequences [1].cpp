class Solution {
public:
    int solve(string& s, string& t, vector<vector<int>>& dp, int i, int j){
        if(j == t.length()) // string t is exhausted
            return 1;
        if(i == s.length()) // string s is exhausted
            return 0;
        if(dp[i][j] != -1) // result already in dp
            return dp[i][j];
        // including s[i] in subsequence
        int include = s[i] == t[j] ? solve(s, t, dp, i+1, j+1) : 0;
        // excluding s[i] from subsequence
        int exclude = solve(s, t, dp, i+1, j);
        // store the result in dp
        dp[i][j] = include + exclude;
        return dp[i][j]; 
    }

    int numDistinct(string s, string t) { // Memoization, T.C.=O(n1*n2), S.C.=O(n1*n2)
        if(s.length() < t.length())
            return 0;
        int n1=s.length(), n2=t.length();
        vector<vector<int>> dp(n1, vector(n2, -1)); // dp of size n1*n2 filled with -1's
        return solve(s, t, dp, 0, 0);
    }
};