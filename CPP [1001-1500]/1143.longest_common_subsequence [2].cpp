class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) { // T.C.=O(n1*n2), S.C.=O(n1*n2), DP
        int n1=s1.length(), n2=s2.length();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1)); // dp of size (n1+1)*(n2+1) filled with -1's
        for(int i=0; i<=n1; i++) // fill the 0th col with 0's
            dp[i][0] = 0;
        for(int j=0; j<=n2; j++) // fill the 0th row with 0's
            dp[0][j] = 0;
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        return dp[n1][n2]; // return the last element in dp
    }
};
// ith index of dp is mapped with (i-1)th index of s1
// jth index of dp is mapped with (j-1)th index of s2
