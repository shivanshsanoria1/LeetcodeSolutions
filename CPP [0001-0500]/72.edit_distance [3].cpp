class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(n2)
    // DP: Tabulation (with Space-Optimization)
    int minDistance(string word1, string word2) { 
        int n1=word1.length(), n2=word2.length();
        vector<int> dp_prev(n2 + 1, 0);
        vector<int> dp_curr(n2 + 1, 0);

        // fill the 0th row with 0,1,2,...,n2
        for(int j=0; j<=n2; j++) 
            dp_prev[j] = j;

        for(int i=1; i<=n1; i++)
        {
            // acts as the 0th col, filled with 0,1,2,...,n1
            dp_curr[0] = i;

            for(int j=1; j<=n2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp_curr[j] = dp_prev[j-1];
                else
                    dp_curr[j] = 1 + min(dp_prev[j-1], min(dp_prev[j], dp_curr[j-1]));
            }

            dp_prev = dp_curr;
        }
        
        return dp_prev[n2];
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