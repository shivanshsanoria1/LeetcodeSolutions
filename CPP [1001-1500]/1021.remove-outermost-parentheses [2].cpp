class Solution {
public:
    string removeOuterParentheses(string s) { //T.C.=O(n) , S.C.=O(1)
        string ans="";
        int c=0;
        for(auto it: s)
        {
            if(it=='(')
            {
                if(c > 0)
                    ans+='(';
                c++;
            }
            else
            {
                if(c > 1)
                    ans+=')';
                c--;
            }
        }
        return ans;
    }
};