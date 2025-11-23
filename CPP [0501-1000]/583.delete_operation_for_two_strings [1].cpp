class Solution {
private:
    int lcs(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        // index out of bounds for any string
        if(i == s1.length() || j == s2.length()) 
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // ith char of s1 matches with jth char of s2
        // move forward in both s1 and s2
        if(s1[i] == s2[j]) 
        {
            dp[i][j] = 1 + lcs(s1, s2, i+1, j+1, dp);
            return dp[i][j];
        }

        // move forward only in s1
        int res1 = lcs(s1, s2, i+1, j, dp); 
        // move forward only in s2
        int res2 = lcs(s1, s2, i, j+1, dp); 
        
        dp[i][j] = max(res1, res2);
        return dp[i][j]; 
    }

public:
    // T.C.=O(n1*n2), S.C.=O(n1*n2)
    // DP: Memoization
    int minDistance(string word1, string word2) {
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return n1 + n2 - 2*lcs(word1, word2, 0, 0, dp);
    }
};

// prerequisite: [1143. longest-common-subsequence]