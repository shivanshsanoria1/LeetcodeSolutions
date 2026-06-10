class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char ch: expression)
        {
            if(ch != ')')
            {
                // no need of ',' they are baiscally useless
                if(ch != ',')
                    st.push(ch);
                continue;
            }

            // to keep track of true and false values 
            // are found or not
            bool t = false;
            bool f = false;
            
            while(st.top() != '(')
            {
                if(st.top() == 't')
                    t = true;
                else // st.top() == 'f'
                    f = true;
                st.pop();
            }
            // pop the '('
            st.pop();

            // operator
            char op = st.top();
            st.pop();

            if(op == '&')
                st.push(f ? 'f' : 't');
            else if(op == '|')
                st.push(t ? 't' : 'f');
            else // op == '!'
                st.push(f ? 't' : 'f');
        
        }

        return st.top() == 't';
    }
};