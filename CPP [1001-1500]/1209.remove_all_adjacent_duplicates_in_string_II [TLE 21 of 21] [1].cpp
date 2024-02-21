class Solution {
public:
    string removeDuplicates(string s, int k) { // T.C.=O(n*k), S.C.=O(n)
        vector<char> st; // using vector as a stack
        for(char ch: s)
        {
            int k2 = k - 1;
            // see if last k-1 chars match with curr char
            int i = st.size() - 1;
            while(i >= 0 && k2 > 0)
            {
                if(st[i] != ch)
                    break;
                k2--;
                i--;
            }
            if(k2 == 0) // pop k-1 chars from stack
            {
                k2 = k - 1;
                while(k2--)
                    st.pop_back();
            }
            else
                st.push_back(ch);
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.back();
            st.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};