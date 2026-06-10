class Solution {
public:
    string greatestLetter(string s) {
        vector<bool> upper(26, false);
        vector<bool> lower(26, false);
        for(char ch: s)
        {
            if(ch >= 'A' && ch <= 'Z') // uppercase
                upper[ch - 'A'] = true;
            else // lowercase
                lower[ch - 'a'] = true;
        }

        string ans = "";
        for(int i=25; i>=0; i--)
            if(upper[i] && lower[i])
            {
                ans += char(i + 'A');
                break;
            }
        return ans;
    }
};