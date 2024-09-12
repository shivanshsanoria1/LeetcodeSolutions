class Solution {
private:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        int n1=s1.length(), n2=s2.length();

        // both indexes i and j are out of bounds
        if(i == n1 && j == n2) 
            return 0;
        // index i is out of bounds, so, 
        // insert the remaining (n2 - j) chars of s2 in s1
        if(i == n1) 
            return n2 - j;
        // index j is out of bounds, so
        // remove the remaining (n1 - i) chars from s1
        if(j == n2) 
            return n1 - i;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
        {
            dp[i][j] = solve(s1, s2, i+1, j+1, dp);
            return dp[i][j];
        }

        int insert = solve(s1, s2, i, j+1, dp);
        int remove = solve(s1, s2, i+1, j, dp);
        int replace = solve(s1, s2, i+1, j+1, dp);

        dp[i][j] = 1 + min(insert, min(remove, replace));
        return dp[i][j]; 
    }

public:
    // T.C.=O(n1*n2), S.C.=O(n1*n2)
    // DP: Memoization
    int minDistance(string word1, string word2) { 
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return solve(word1, word2, 0, 0, dp);
    }
};