class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int minimumDeletions(string s) {
        stack<char> st;
        int deletions = 0;

        for(char ch: s)
        {
            if(ch == 'b')
                st.push(ch);
            else if(!st.empty() && st.top() == 'b')
            {
                st.pop();
                deletions++;
            }   
        }

        return deletions;
    }
};