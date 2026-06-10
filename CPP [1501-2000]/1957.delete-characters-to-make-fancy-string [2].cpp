class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string makeFancyString(string s) {
        char prev2 = '#';
        char prev1 = '#';
        string ans = "";

        for(char ch: s)
        {
            if(prev1 == '#')
            {
                prev1 = ch;
                ans += ch;
            }
            else if(prev2 == '#' || prev1 != ch || prev2 != ch)
            {
                prev2 = prev1;
                prev1 = ch;
                ans += ch;
            }
        }

        return ans;
    }
};