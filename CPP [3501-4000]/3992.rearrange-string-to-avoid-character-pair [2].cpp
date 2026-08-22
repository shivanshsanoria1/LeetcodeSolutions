class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    string rearrangeString(string s, char x, char y) {
        if(x > y)
            sort(s.begin(), s.end());
        else // x < y
            sort(s.begin(), s.end(), greater<char>());

        return s;
    }
};