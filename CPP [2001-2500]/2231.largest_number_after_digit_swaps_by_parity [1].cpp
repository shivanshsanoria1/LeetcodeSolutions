class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);

        string odds = ""; // to store the odd digits
        string evens = ""; // to store the even digits
        for(int i=0; i<s.length(); i++)
        {
            if((s[i] - '0') % 2 == 0) // even
                evens += s[i];
            else // odd
                odds += s[i];
        }
        // sort the 'odds' and 'evens' strings in decreasing order
        sort(odds.begin(), odds.end(), greater<char>());
        sort(evens.begin(), evens.end(), greater<char>());

        int idx_O = 0, idx_E = 0;
        string ans = "";
        for(int i=0; i<s.length(); i++)
        {
            if((s[i] - '0') % 2 == 0) // even
            {
                ans += evens[idx_E];
                idx_E++;
            }
            else // odd
            {
                ans += odds[idx_O];
                idx_O++;
            }
        }

        return stoi(ans);
    }
};