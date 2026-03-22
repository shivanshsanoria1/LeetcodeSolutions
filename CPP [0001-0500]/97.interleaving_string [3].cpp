class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) { // DP, T.C.=O(n1*n2), S.C.=O(n1*n2)
        int n1=s1.length(), n2=s2.length(), n3=s3.length();
        // sum of lengths of s1 and s2 must be equal to length of s3
        if(n1 + n2 != n3)
            return false;
        // the sum of freq of chars in s1 and s2 must match with those of s3
        vector<int> freq(26, 0);
        for(char ch: s1)
            freq[ch - 'a']++;
        for(char ch: s2)
            freq[ch - 'a']++;
        for(char ch: s3)
            freq[ch - 'a']--;
        for(int i=0; i<26; i++)
            if(freq[i] != 0)
                return false;
        // dp of size (n1 + 1)*(n2 + 1) filled with false's
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[0][0] = true; // interleaving is always possible if both both s1 and s2 are empty
        for(int j=1; j<=n2; j++) // 0th row (s1 is empty)
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        for(int i=1; i<=n1; i++) // 0th col (s2 is empty)
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++)
                if((dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]))
                    dp[i][j] = true;
        return dp[n1][n2];
    }
};
// dp[i][j]: string s1 and s2 (ending at indexes i-1 and j-1 respectively) can be interleaved or not
// to form string s3 (ending at index i+j-1) 