class Solution {
public:
    string removeDuplicates(string s, int k) { // T.C.=O(n), S.C.=O(n)
        stack<pair<char, int>> st; // {char, consecutive freq}
        for(char ch: s)
        {
            // curr char matches with char at stack top
            if(!st.empty() && st.top().first == ch)
            {
                // increment the stack top char's consecutive freq
                st.top().second++;
                // pop the stack top if its char's consecutive freq reaches k
                if(st.top().second == k)
                    st.pop();
            }
            // push curr char with its consecutive freq as 1
            else
                st.push({ch, 1});
        }
        string ans = "";
        while(!st.empty())
        {
            auto [ch, freq] = st.top();
            while(freq--)
                ans += ch;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};