class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2*n) + to_string(3*n);
        if(s.length() != 9)
            return false;
        vector<bool> seen(10, false);
        for(char ch: s)
        {
            if(seen[ch] || ch == '0')
                return false;
            seen[ch] = true;
        }
        return true;
    }
};