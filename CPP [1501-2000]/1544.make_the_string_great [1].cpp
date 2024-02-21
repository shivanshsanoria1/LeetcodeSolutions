class Solution {
public:
    string makeGood(string s) {
        string ans="";
        stack<char> st;
        st.push(s[0]); //push the first char in stack
        for(int i=1; i<s.length(); i++)
        {
            if(!st.empty() && abs(s[i]-st.top())==32) //if curr char and stack top form an uppercase lowercase pair
                st.pop();                             //pop the stack top
            else //else push the curr char into the stack
                st.push(s[i]);
        }
        while(!st.empty()) //empty the stack into the ans string
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};