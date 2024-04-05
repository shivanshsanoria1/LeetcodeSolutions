class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    string makeGood(string s) {
        stack<char> st;
        // push the first char in stack
        st.push(s[0]); 

        for(int i=1; i<s.length(); i++)
        {
            // curr char and char at stack top form an uppercase-lowercase pair
            if(!st.empty() && abs(s[i] - st.top()) == 32) 
                st.pop();
            else
                st.push(s[i]);
        }

        // empty the stack into the ans string
        string ans = "";
        while(!st.empty()) 
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};