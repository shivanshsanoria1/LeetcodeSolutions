class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    string reverseParentheses(string s) {
        // stores index of '('
        stack<int> st;
        string ans = "";

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
                st.push(ans.length());
            else if(s[i] == ')')
            {

                reverse(ans.begin() + st.top(), ans.end());
                st.pop();
            }
            else
                ans += s[i];
        }

        return ans;
    }
};