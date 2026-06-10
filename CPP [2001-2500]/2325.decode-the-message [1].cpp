class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp; // encoded char -> decoded char
        char alpha = 'a';
        for(char ch: key)
            if(ch != ' ' && !mp[ch])
            {
                mp[ch] = alpha;
                alpha++;
                if(alpha > 'z')
                    break;
            }

        string ans = "";
        for(char ch: message)
        {
            if(ch == ' ')
                ans += ' ';
            else // find the decoded char from map
                ans += mp[ch]; 
        }
        return ans;
    }
};