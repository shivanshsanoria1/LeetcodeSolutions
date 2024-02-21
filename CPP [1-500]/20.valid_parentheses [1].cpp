class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> st;
        char c;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') //push the left brackets into the stack
            {
                st.push(s[i]);
                continue;
            }
            if(st.empty())  //no opening brackets
                return false;
            switch(s[i])
            {
                case ')':
                    c=st.top();
                    st.pop();
                    if(c=='{' || c=='[')
                        return false;
                    break;
                case '}':
                    c=st.top();
                    st.pop();
                    if(c=='(' || c=='[')
                        return false;
                    break;
                case ']':
                    c=st.top();
                    st.pop();
                    if(c=='(' || c=='{')
                        return false;
                    break;
            }
        }
        return(st.empty()); // if stack is empty return true
    }
};