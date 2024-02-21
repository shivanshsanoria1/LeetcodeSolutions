class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int max_size=0;
        for(auto it: s)
        {
            if(it =='(')
            {
                st.push(it);
                if(st.size() > max_size) //new max size found
                    max_size=st.size(); //update max size
            }
            else if(it ==')')
                st.pop();
        }
        return max_size;
    }
};