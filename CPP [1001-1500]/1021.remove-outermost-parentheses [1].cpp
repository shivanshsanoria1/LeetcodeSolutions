class Solution {
public:
    string removeOuterParentheses(string s) { //T.C.=O(n) , S.C.=O(n)
        string ans="";
        stack<char> st;
        for(auto it: s)
        {
            if(it=='(')
            {
                if(st.size() > 0)
                    ans+='(';
                st.push(it);
            }
            else
            {
                if(st.size() > 1)
                    ans+=')';
                st.pop();
            }
        }
        return ans;
    }
};