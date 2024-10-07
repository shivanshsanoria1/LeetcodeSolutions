class Solution {
private:
    int convertChToNum(char ch){
        if(ch == '(')
            return 1;
        if(ch == ')')
            return -1;
        if(ch == '{')
            return 2;
        if(ch == '}')
            return -2;
        if(ch == '[')
            return 3;
        if(ch == ']')
            return -3;
        
        return 0;
    }

public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch: s)
        {
            int num = convertChToNum(ch);

            // push the left-bracket into the stack
            if(num > 0)
            {
                st.push(num);
                continue;
            }

            // no left-bracket to match with the curr right-bracket
            if(st.empty())
                return false;
            
            int tp = st.top();
            st.pop();

            // curr right-bracket does the match 
            // with the one at stack top
            if(num + tp != 0)
                return false;
        }

        return st.empty();
    }
};

/*
# '(': 1, ')': -1
# '{': 2, '}': -2
# '[': 3, ']': -3
*/