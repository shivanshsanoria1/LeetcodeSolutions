class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<bool> st; //no need to push strings into stack, just use some random bool value to save space
        for(auto it: logs)
        {
            if(it == "../")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(it != "./")
                st.push(true);
        }
        return st.size();
    }
};