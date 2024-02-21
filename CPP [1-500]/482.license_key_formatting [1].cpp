class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int alphaNumCount = 0;
        for(char ch: s)
            if(ch != '-')
                alphaNumCount++;

        string ans = "";
        int i = 0;
        while(ans.length() < alphaNumCount % k)
        {
            if(s[i] != '-')
                ans += toupper(s[i]);
            i++;
        }
        if(ans.length() > 0 && ans.length() < alphaNumCount)
            ans += "-";

        string group = "";
        while(i < s.length())
        {
            if(group.length() == k)
            {
                ans += group + "-";
                group = "";
            }
            if(s[i] != '-')
                group += toupper(s[i]);
            i++;
        }
        ans += group;
        if(ans.length() > 0 && ans.back() == '-')
            ans.pop_back();

        return ans;
    }
};