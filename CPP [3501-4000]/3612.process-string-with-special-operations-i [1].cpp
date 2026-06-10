class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    // Simulation
    string processStr(string s) {
        string ans = "";
        
        for(char ch: s)
        {
            if(ch >= 'a' && ch <= 'z')
                ans += ch;
            else if(ch == '#')
                ans += ans;
            else if(ch == '%')
                reverse(ans.begin(), ans.end());
            else if(ch == '*' && !ans.empty())
                ans.pop_back();
        }

        return ans;
    }
};