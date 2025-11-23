class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s)
        {
            // push the left-bracket into the stack
            if(ch == '(' || ch == '{' || ch == '[') 
            {
                st.push(ch);
                continue;
            }

            // no left-bracket to match with the curr right-bracket
            if(st.empty())
                return false;

            char tp = st.top();
            st.pop();

            // curr right-bracket does the match 
            // with the one at stack top
            if(ch == ')' && tp != '(') 
                return false;
            if(ch == '}' && tp != '{')
                return false;
            if(ch == ']' && tp != '[')
                return false;
        }

        return st.empty();
    }
};