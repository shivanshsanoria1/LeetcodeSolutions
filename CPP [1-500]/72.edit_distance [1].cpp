class Solution {
public:
    int solve(vector<vector<int>>& dp, string& s1, string& s2, int i, int j){
        int n1=s1.length(), n2=s2.length();
        if(i == n1 && j == n2) // both i and j index out of bounds
            return 0;
        if(i == n1) // only i index out of bounds
            return n2-j;
        if(j == n2) // only j index out of bounds
            return n1-i;
        if(s1[i] == s2[j]) // matching chars found
        {
            if(dp[i+1][j+1] > 0)
                return dp[i+1][j+1];
            dp[i+1][j+1] = solve(dp, s1, s2, i+1, j+1);
            return dp[i+1][j+1];
        }
        if(dp[i][j+1] == 0)
            dp[i][j+1] = solve(dp, s1, s2, i, j+1);
        if(dp[i+1][j] == 0)
            dp[i+1][j] = solve(dp, s1, s2, i+1, j);
        if(dp[i+1][j+1] == 0)
            dp[i+1][j+1] = solve(dp, s1, s2, i+1, j+1);
        int insert = dp[i][j+1];
        int remove = dp[i+1][j];
        int replace = dp[i+1][j+1];
        dp[i][j] = 1 + min(insert, min(remove, replace));
        return dp[i][j];
    }

    int minDistance(string word1, string word2) { // Memoization, T.C.=O(n1*n2), S.C.=O(n1*n2)
        int n1=word1.length(), n2=word2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0)); // dp of size (n1+1)*(n2+1) filled with 0's
        return solve(dp, word1, word2, 0, 0);
    }
};