class Solution {
public:
    void solve(vector<string>& ans, string& s, int left, int right) //left and right are num of '(' and ')' remaining
    {
        if(left==0 && right==0) //no more parenthesis are remaining
        {
            ans.push_back(s);
            return;
        }
        if(left > 0) //left parenthesis are remaining
        {
            s += "(";
            solve(ans,s,left-1,right);
            s.pop_back();
        }
        if(right > left) //more right parenthesis are remaining than the left parenthesis
        {
            s += ")";
            solve(ans,s,left,right-1);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        solve(ans,s,n,n);
        return ans;
    }
};