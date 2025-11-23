class Solution {
public:
    int numDistinct(string s, string t) { // Tabulation, T.C.=O(n1*n2), S.C.=O(n1*n2)
        if(s.length() < t.length())
            return 0;
        int n1=s.length(), n2=t.length();
        // dp of size (n1+1)*(n2+1) filled with 0's
        vector<vector<unsigned int>> dp(n1+1, vector<unsigned int>(n2+1, 0));
        for(int i=0; i<=n1; i++) // 0th col
            dp[i][0] = 1;
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
            {
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        return dp[n1][n2];
    }
};
/*
# dp[i][j]: num of subsequences in string s matching with string t taking the strings 
  s from index 0 to i-1 and t from index 0 to j-1
# dp[i][j] is mapped with s[i-1] and t[j-1]
# 0th row: filled with 0's; s is empty and t is non-empty, ie, 0 subsequence possible 
# 0th col: filled with 1's; s is non-empty and t is empty, ie, 1 subsequence possible 
# dp[0][0] = 1; both s and t are empty, ie, 1 subsequence possible 
# unsigned int dp is taken to prevent int overflow
*/