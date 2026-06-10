class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    long long countSubstrings(string s, char c) {
        long long int freq = 0;
        for(char ch: s)
            if(ch == c)
                freq++;
        return (freq * (freq + 1)) / 2;
    }
};