class Solution {
private:
    // a=1, b=2, c=3, ..., z=26
    int getCharVal(const char ch){
        return ch - 'a' + 1;
    }

    // returns true if substring of s1 starting at 
    // index 'start' and of length 'len' matches with s2
    bool areMatching(const string& s1, const int start, const int len, const string& s2){
        for(int i = start; i < start + len; i++)
            if(s1[i] != s2[i - start])
                return false;

        return true;
    }

public:
    // T.C.=O(n1 * n2), S.C.=O(1)
    // Rolling-hash
    int strStr(string haystack, string needle) { 
        // rename the parameters
        const string& s1 = haystack;
        const string& s2 = needle;

        const int n1 = s1.length(), n2 = s2.length();
        // s2 cannot not be longer than s1
        if(n1 < n2) 
            return -1;

        // hash of s2
        int hash2 = 0;
        for(const char ch: s2)
            hash2 += getCharVal(ch);
        
        // hash of s1 in index-range [0, n2-1]
        int hash1 = 0;
        for(int i=0; i<n2; i++)
            hash1 += getCharVal(s1[i]);
        
        if(hash1 == hash2 && areMatching(s1, 0, n2, s2))
            return 0;

        for(int i=1; i <= n1-n2; i++){
            hash1 -= getCharVal(s1[i-1]);
            hash1 += getCharVal(s1[i+n2-1]);
            
            if(hash1 == hash2 && areMatching(s1, i, n2, s2))
                return i;
        }

        // s2 not found in s1
        return -1;
    }
};