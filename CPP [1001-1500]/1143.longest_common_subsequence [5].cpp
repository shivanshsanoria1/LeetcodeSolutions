class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(n2)
    // DP: Tabulation (with Space-Optimization)
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();

        vector<int> dp_prev(n2 + 1, 0);
        vector<int> dp_curr(n2 + 1, 0);

        for(int i=1; i<=n1; i++)
        {
            for(int j=1; j<=n2; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp_curr[j] = 1 + dp_prev[j-1];
                else
                    dp_curr[j] = max(dp_prev[j], dp_curr[j-1]);
            }
            
            dp_prev = dp_curr;
        }
        
        return dp_prev[n2];
    }
};

// dp[i][j] is mapped with s1[i-1] and s2[j-1]
// in other words,
// s1[i] and s2[j] is mapped with dp[i+1][j+1]