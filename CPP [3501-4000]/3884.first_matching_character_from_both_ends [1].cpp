class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int firstMatchingIndex(string s) {
        const int n = s.length();
        for(int i=0; i<=(n-1)/2; i++)
            if(s[i] == s[n-1-i])
                return i;
        return -1;  
    }
};