class Solution {
public:
    string removeStars(string s) { // S.C.=O(n)
        stack<char> st;
        for(char ch: s)
        {
            if(ch != '*')
                st.push(ch);
            else
                st.pop();
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// here '*' is essentialy working as backspace 