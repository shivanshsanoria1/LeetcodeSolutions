class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string makeGood(string s) {
        string ans = "";
        ans += s[0];

        for(int i=1; i<s.length(); i++)
        {
            // curr char and last char in 'ans' form an uppercase-lowercase pair
            if(!ans.empty() && abs(s[i] - ans.back()) == 32) 
                ans.pop_back();
            else
                ans += s[i];
        }

        return ans;
    }
};