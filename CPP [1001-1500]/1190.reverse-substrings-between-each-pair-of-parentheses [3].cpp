class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    string reverseParentheses(string s) {
        // stores index of '('
        stack<int> st;
        int n=s.length();
        // partner[i]: index of partner-parenthesis, 
        // and -1 if index i is not a parenthesis itself
        vector<int> partner(n, -1);

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
            {
                int j = st.top();
                st.pop();
                partner[i] = j;
                partner[j] = i;
            }
        }

        string ans = "";
        // dir: 1 (left to right)
        //     -1 (right to left)
        for(int i=0, dir = 1; i<n; i += dir)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                // move to the partner-parenthesis
                i = partner[i];
                // reverse the direction
                dir = -1*dir;
            }
            else
                ans += s[i];
        }

        return ans;
    }
};