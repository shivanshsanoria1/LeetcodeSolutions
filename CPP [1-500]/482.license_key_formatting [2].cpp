class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int alphaNumCount = 0;
        for(char ch: s)
            if(ch != '-')
                alphaNumCount++;

        string ans = "";
        string group = "";
        for(int i=s.length()-1; i>=0; i--)
        {
            if(group.length() == k)
            {
                ans += group + "-";
                group = "";
            }
            if(s[i] == '-')
                continue;
            group += toupper(s[i]);
        }
        ans += group;
        if(ans.length() > 0 && ans.back() == '-')
            ans.pop_back();

        reverse(ans.begin(), ans.end());
        return ans;
    }
};