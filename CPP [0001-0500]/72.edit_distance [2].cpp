class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(n1*n2)
    // DP: Tabulation
    int minDistance(string word1, string word2) { 
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // fill the 0th row with 0,1,2,...,n2
        for(int j=0; j<=n2; j++) 
            dp[0][j] = j;
        // fill the 0th col with 0,1,2,...,n1
        for(int i=0; i<=n1; i++) 
            dp[i][0] = i;

        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        
        return dp[n1][n2];
    }
};

/*
# dp[i][j] is mapped with s1[i-1] and s2[j-1]
  in other words, 
  s1[i] and s2[j] is mapped with dp[i+1][j+1]

# in dp[][]:
  # 0th row represents s1 is empty and s2 is unchanged
    so j insert operations are needed for the jth col
  # 0th col represents s1 is unchanged and s2 is empty
    so j delete operations are needed for the ith row
*/