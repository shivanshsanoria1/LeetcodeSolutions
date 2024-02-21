class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        string ans = "";
        ans += s[0];
        int len = 1;
        for(int i=1; i<n; i++)
        {
            if(s[i-1] == s[i])
                len++;
            else
                len = 1;
                
            if(len <= 2)
                ans += s[i];
        }
        return ans;
    }
};