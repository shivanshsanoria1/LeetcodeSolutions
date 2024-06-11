class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string clearDigits(string s) {
        string ans = "";

        for(char ch: s)
        {
            if(isdigit(ch))
                ans.pop_back();
            else
                ans += ch;
        }

        return ans;
    }
};