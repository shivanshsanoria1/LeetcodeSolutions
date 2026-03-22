class Solution {
public:
    bool solve(vector<vector<int>>& dp, string& s1, string& s2, string& s3, int i, int j){
        int n1=s1.length(), n2=s2.length(), n3=s3.length();
        int k = i + j; // calculate index k
        if(k == n3) // reached the end of string 3
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        bool left = (i < n1 && s1[i] == s3[k]) ? solve(dp, s1, s2, s3, i+1, j) : false;
        bool right = (j < n2 && s2[j] == s3[k]) ? solve(dp, s1, s2, s3, i, j+1) : false;
        dp[i][j] = left || right;
        return dp[i][j]; 
    }

    bool isInterleave(string s1, string s2, string s3) { // Memoization, T.C.=O(n1*n2), S.C.=O(n1*n2)
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
        // dp of size (n1 + 1)*(n2 + 1) filled with -1's 
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1)); 
        // check recursively starting at indexes 0 in all strings
        return solve(dp, s1, s2, s3, 0, 0);
    }
};
/*
# dp[i][j]: interleaving string s3 (ending at index k=i+j) can be formed or not 
from strings s1, s2 ending at index i,j respectively
# dp of size (n1 + 1)*(n2 + 1) is taken instead of n1*n2 to prevent index out of bounds case
*/