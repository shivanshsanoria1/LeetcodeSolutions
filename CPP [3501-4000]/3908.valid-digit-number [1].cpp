class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    bool validDigit(int n, int x) {
        string s = to_string(n);

        if(s[0] -'0' == x)
            return false;
        
        for(int i=1; i<s.length(); i++)
            if(s[i] - '0' == x)
                return true;
        
        return false;
    }
};