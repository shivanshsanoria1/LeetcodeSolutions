class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    // Simulation
    char processStr(string s, long long k) {
        string res = "";
        
        for(char ch: s)
        {
            if(ch >= 'a' && ch <= 'z')
                res += ch;
            else if(ch == '#')
                res += res;
            else if(ch == '%')
                reverse(res.begin(), res.end());
            else if(ch == '*' && !res.empty())
                res.pop_back();
        }

        return k < res.length() ? res[k] : '.';
    }
};