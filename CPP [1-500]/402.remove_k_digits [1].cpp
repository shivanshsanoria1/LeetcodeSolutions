class Solution {
public:
    string removeKdigits(string num, int k) { // T.C.=O(n), S.C.=O(n)
        stack<char> st; // monotonic increasing stack
        // add chars from num into stack, while maintaining stack in increasing order
        for(char ch: num)
        {
            // pop atmost k chars
            while(k > 0 && !st.empty() && st.top() > ch)
            {
                k--;
                st.pop();
            }
            st.push(ch);
        }
        // empty the stack into ans
        string ans = "";
        // ensure that k chars are popped 
        while(k > 0 && !st.empty())
        {
            k--;
            st.pop();
        }
        // after k chars are popped add the leftover chars to ans
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        // remove the leading zeros from ans, 
        // which are actually trailing zeros at this point in ans
        int i = ans.length() - 1;
        while(i >= 0 && ans[i] == '0')
        {
            ans.pop_back();
            i--;
        }
        // reverse the ans
        reverse(ans.begin(), ans.end());
        // replace empty string with 0 before returning
        return ans == "" ? "0" : ans;
    }
};