class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(n1*n2)
    // DP: Tabulation
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));

        for(int i=0; i<n1; i++)
            for(int j=0; j<n2; j++)
            {
                int northWest = i-1 >= 0 && j-1 >= 0 ? dp[i-1][j-1] : 0;
                int north = i-1 >= 0 ? dp[i-1][j] : 0;
                int west = j-1 >= 0 ? dp[i][j-1] : 0;
                
                dp[i][j] = s1[i] == s2[j] ? 1 + northWest : max(north, west);
            }
        
        return dp[n1-1][n2-1];
    }
};