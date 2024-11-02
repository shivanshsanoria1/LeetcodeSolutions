class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string makeFancyString(string s) {
        int len = 1;
        string ans = "";
        ans += s[0];

        for(int i=1; i<s.length(); i++)
        {
            if(s[i-1] == s[i])
                len++;
            else
                len = 1;
                
            if(len < 3)
                ans += s[i];
        }

        return ans;
    }
};