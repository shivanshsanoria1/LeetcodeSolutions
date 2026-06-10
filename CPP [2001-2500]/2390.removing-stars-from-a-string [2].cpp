class Solution {
public:
    string removeStars(string s) { // S.C.=O(1)
        string ans = "";
        for(char ch: s)
        {
            if(ch != '*')
                ans += ch;
            else
                ans.pop_back();
        }
        return ans;
    }
};
// here '*' is essentialy working as backspace 