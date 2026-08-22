class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string rearrangeString(string s, char x, char y) {
        int countY = 0;
        for(const char ch: s)
            if(ch == y)
                countY++;
        
        string t = string(countY, y);
        for(const char ch: s)
            if(ch != y)
                t += ch;
        
        return t;
    }
};