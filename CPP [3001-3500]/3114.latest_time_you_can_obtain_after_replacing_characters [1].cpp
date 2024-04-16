class Solution {
public:
    string findLatestTime(string s) {
        char m0 = s[4] == '?' ? '9' : s[4];
        char m1 = s[3] == '?' ? '5' : s[3];

        char h0 = s[1];
        char h1 = s[0];

        // h1 and h0 are missing
        if(h1 == '?' && h0 == '?')
        {
            h0 = '1';
            h1 = '1';
        }
        // only h0 is missing
        else if(h1 != '?' && h0 == '?')
            h0 = h1 == '1' ? '1' : '9';
        // only h1 is missing
        else if(h1 == '?' && h0 != '?')
            h1 = h0 > '1' ? '0' : '1';
        
        string ans = "";
        ans += h1;
        ans += h0;
        ans += ':';
        ans += m1;
        ans += m0;
        return ans;
    }
};
// assume the string to be of form:
// "h1 h0 : m1 m0"