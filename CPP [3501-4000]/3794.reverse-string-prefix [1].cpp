class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string reversePrefix(string s, int k) {
        reverse(s.begin(), s.begin() + k);
        
        return s;
    }
};