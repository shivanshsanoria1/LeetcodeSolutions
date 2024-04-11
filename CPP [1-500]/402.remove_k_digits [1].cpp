class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Monotonic (increasing / non-decreasing) stack
    string removeKdigits(string num, int k) { 
        stack<char> st; 

        // add chars from num into stack, 
        // while maintaining stack in increasing order
        for(char ch: num)
        {
            // pop atmost k chars which are > curr-char
            while(k > 0 && !st.empty() && st.top() > ch)
            {
                k--;
                st.pop();
            }
            st.push(ch);
        }

        // ensure that k chars are popped 
        while(k > 0 && !st.empty())
        {
            k--;
            st.pop();
        }

        string ans = "";
        // after k chars are popped add the leftover chars to ans
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        // remove the leading zeros from ans, which are actually 
        // trailing zeros at this point in ans
        for(int i=ans.length()-1; i >= 0 && ans[i] == '0'; i--)
            ans.pop_back();

        // reverse the ans
        reverse(ans.begin(), ans.end());

        // replace empty string with 0 before returning
        return ans == "" ? "0" : ans;
    }
};