class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        stack<char> st;
        st.push(s[0]); //push the first char in stack
        for(int i=1; i<s.length(); i++)
        {
            if(!st.empty() && s[i]==st.top()) //if curr char and stack top are equal then pop the stack top
                st.pop();
            else //else push the curr char into the stack
                st.push(s[i]);
        }
        while(!st.empty()) //empty the stack into the ans string
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};