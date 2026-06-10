class Solution {
public:
    // T.C.=O(n + m), S.C.=O(n)
    // n: length of 's', m: size of spaces[]
    string addSpaces(string s, vector<int>& spaces) {
        string ans = s.substr(0, spaces[0]);

        for(int i=1; i<spaces.size(); i++)
            ans += " " + s.substr(spaces[i-1], spaces[i] - spaces[i-1]);

        ans += " " + s.substr(spaces.back());

        return ans;
    }
};