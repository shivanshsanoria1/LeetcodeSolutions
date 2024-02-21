class Solution {
public:
    int lcs(string& s1, string& s2, int i, int j)
    {
        if(i==s1.length() || j==s2.length()) //for any string index is out of bounds
            return 0;
        if(s1[i] == s2[j]) //ith char of s1 matches with jth char of s2
            return 1 + lcs(s1,s2,i+1,j+1); //move forward in both s1 and s2
        int a = lcs(s1,s2,i+1,j); //move forward in s1
        int b = lcs(s1,s2,i,j+1); //move forward in s2
        return max(a,b);
    }
    
    int longestCommonSubsequence(string s1, string s2) { //recursion
        return lcs(s1,s2,0,0);
    }
};