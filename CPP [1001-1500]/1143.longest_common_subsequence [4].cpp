class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(n1*n2)
    // DP: Tabulation
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        
        return dp[n1][n2];
    }
};

// dp[i][j] is mapped with s1[i-1] and s2[j-1]
// in other words,
// s1[i] and s2[j] is mapped with dp[i+1][j+1]