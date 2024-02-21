class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char ch: s)
        {
            bool cond1 = ch == 'B' && !st.empty() && st.top() == 'A';
            bool cond2 = ch == 'D' && !st.empty() && st.top() == 'C';
            if(cond1 || cond2)
                st.pop();
            else
                st.push(ch);
        }
        return st.size();
    }
};