class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token: tokens)
        {
            // curr is not an operator, ie, is a number so push it in stack
            if(token != "+" && token != "-" && token != "*" && token != "/") 
            {
                st.push(stoi(token)); 
                continue;
            }

            // pop 2 elements from stack- B and A
            int b = st.top(); 
            st.pop();
            int a = st.top();
            st.pop();

            // find the result of A operator B and push it in stack
            int res = -1; 
            if(token == "+")
                res = a+b;
            else if(token == "-")
                res = a-b;
            else if(token == "*")
                res = a*b;
            else // token == "/"
                res = a/b;
            st.push(res);
        }
        return st.top();
    }
};