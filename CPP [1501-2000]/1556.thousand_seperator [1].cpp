class Solution {
public:
    string thousandSeparator(int n) {
        string ans = "";
        string s = to_string(n);
        int t = 0;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(t == 3)
            {
                ans += '.';
                t = 0;
            }
            ans += s[i];
            t++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};