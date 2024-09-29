class Solution {
private:
    // returns true if substring of s1 starting at index i 
    // and the entire string s2 differ by atmost 1 char
    bool areAlmostEqual(string& s1, string& s2, int i){
        int mismatch = 0;
        for(int j=0; j<s2.length(); j++)
            if(s1[j+i] != s2[j] && ++mismatch == 2)
                return false;

        return true;
    }

public:
    // T.C.=O(n1*n2), S.C.=O(1)
    int minStartingIndex(string s, string pattern) {
        int n1=s.length(), n2=pattern.length();

        for(int i=0; i<=n1-n2; i++)
            if(areAlmostEqual(s, pattern, i))
                return i;

        return -1;
    }
};