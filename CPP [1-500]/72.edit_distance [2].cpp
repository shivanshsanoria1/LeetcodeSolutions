class Solution {
public:
    int minDistance(string word1, string word2) { // DP, T.C.=O(n1*n2), S.C.=O(n1*n2)
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1)); // dp of size (n1+1)*(n2+1)
        for(int j=0; j<=n2; j++) // fill the 0th row with 0,1,2,3,...
            dp[0][j] = j;
        for(int i=0; i<=n1; i++) // fill the 0th col with 0,1,2,3,...
            dp[i][0] = i;
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
            {   
                // no operation needed if chars match
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                // 1 operation is needed for insert, remove, update
                else
                {   
                    int insert = dp[i][j-1];
                    int remove = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    dp[i][j] = 1 + min(insert, min(remove, replace));
                }
            }
        return dp[n1][n2];
    }
};
// dp[i][j] is mapped with s1[i-1] and s2[j-1]