class Solution {
private:
    int lcs(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        if(i == s1.length() || j == s2.length()) 
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // no char deletion required in s1 and s2
        if(s1[i] == s2[j]) 
        {
            dp[i][j] = int(s1[i]) + lcs(s1, s2, i+1, j+1, dp);
            return dp[i][j];
        }

        // delete the ith char from s1
        int res1 = lcs(s1, s2, i+1, j, dp); 
        // delete the jth char from s2
        int res2 = lcs(s1, s2, i, j+1, dp); 
        
        dp[i][j] = max(res1, res2);
        return dp[i][j]; 
    }

public:
    // T.C.=O(n1*n2), S.C.=O(n1*n2)
    // DP: Memoization
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        int lcs_sum = lcs(s1, s2, 0, 0, dp);

        int sum1 = 0;
        for(char ch: s1)
            sum1 += int(ch);
        
        int sum2 = 0;
        for(char ch: s2)
            sum2 += int(ch);

        return sum1 + sum2 - 2*lcs_sum;
    }
};

// prerequisite: [1143. longest-common-subsequence]