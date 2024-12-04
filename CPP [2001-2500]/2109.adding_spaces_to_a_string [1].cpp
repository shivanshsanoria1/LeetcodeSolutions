class Solution {
public:
    // T.C.=O(n + m), S.C.=O(1)
    // n: length of 's', m: size of spaces[]
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";

        for(int i=0, j=0; i<s.length(); i++)
        {
            if(j<spaces.size() && spaces[j] == i)
            {
                ans += " ";
                j++;
            }
            ans += s[i];
        }

        return ans;
    }
};