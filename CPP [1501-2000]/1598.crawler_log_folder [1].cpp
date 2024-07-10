class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int minOperations(vector<string>& logs) {
        stack<string> st;
        
        for(string& log: logs)
        {
            if(log == "../")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(log != "./")
                st.push(log);
        }

        return st.size();
    }
};