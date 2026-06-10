class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int maxDepth(string s) {
        stack<char> st;
        int maxDepth = 0;

        for(char ch: s)
        {
            if(ch == '(')
            {
                st.push('(');
                maxDepth = max(maxDepth, (int)st.size());
            }
            else if(ch == ')')
                st.pop();
        }

        return maxDepth;
    }
};