class Solution {
public:
    void solve(vector<string>& ans, int n, string& s, int left, int right) //left and right are num of '(' and ')' used currently
    {
        if(left==n && right==n) //no more parenthesis are remaining
        {
            ans.push_back(s);
            return;
        }
        if(left < n) //left parenthesis are remaining
        {
            s += "(";
            solve(ans,n,s,left+1,right);
            s.pop_back();
        }
        if(left > right) //currently there are more left parenthesis than right parenthesis
        {
            s += ")";
            solve(ans,n,s,left,right+1);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        solve(ans,n,s,0,0); //initially left and right parenthesis used are 0
        return ans;
    }
};