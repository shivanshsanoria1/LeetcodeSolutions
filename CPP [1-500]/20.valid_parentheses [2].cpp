class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') //push the left brackets into the stack
            {
                st.push(s[i]);
                continue;
            }
            if(st.empty()) //no opening brackets
                return false;
            char ch= st.top();
            st.pop();
            if(s[i]==')' && (ch=='{' || ch=='[')) //if curr right bracket does the match with the stack top
                return false;
            if(s[i]=='}' && (ch=='(' || ch=='['))
                return false;
            if(s[i]==']' && (ch=='(' || ch=='{'))
                return false;
        }
        return st.empty() ? true : false; //if stack is empty then string is valid
    }
};