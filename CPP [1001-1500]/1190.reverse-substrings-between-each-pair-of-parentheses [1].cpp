class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    string reverseParentheses(string s) {
        // stores index of '('
        stack<int> st;
        // stores indexes of each '(' and ')' pair
        vector<pair<int, int>> idxs;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
            {
                idxs.push_back({st.top(), i});
                st.pop();
            }
        }

        // reverse the substrings in index-range [left, right]
        for(auto [left, right]: idxs)
            reverse(s.begin() + left, s.begin() + right + 1);

        string ans = "";
        for(char ch: s)
            if(ch != '(' && ch != ')')
                ans += ch;

        return ans;
    }
};