class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k){
        int n1=s1.length(), n2=s2.length(), n3=s3.length();
        if(k == n3) // reached the end of string 3
            return true;
        bool left = (i < n1 && s1[i] == s3[k]) ? solve(s1, s2, s3, i+1, j, k+1) : false;
        bool right = (j < n2 && s2[j] == s3[k]) ? solve(s1, s2, s3, i, j+1, k+1) : false;
        return left || right;
    }

    bool isInterleave(string s1, string s2, string s3) { // Recusion, T.C.=O(2^(n1 + n2))
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
        // check recursively starting at indexes 0 in all 3 strings
        return solve(s1, s2, s3, 0, 0, 0);
    }
};