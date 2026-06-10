class Solution {
private:
    int lcs(string& s1, string& s2, int i, int j){
        // index out of bounds for any string
        if(i == s1.length() || j == s2.length()) 
            return 0;

        // ith char of s1 matches with jth char of s2
        // move forward in both s1 and s2
        if(s1[i] == s2[j]) 
            return 1 + lcs(s1, s2, i+1, j+1); 

        // move forward only in s1
        int res1 = lcs(s1, s2, i+1, j); 
        // move forward only in s2
        int res2 = lcs(s1, s2, i, j+1); 

        return max(res1, res2);
    }

public:
    // Recursion
    int longestCommonSubsequence(string s1, string s2) { 
        return lcs(s1, s2, 0, 0);
    }
};