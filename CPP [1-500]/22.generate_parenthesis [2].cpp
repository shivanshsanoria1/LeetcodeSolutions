class Solution {
public:
    vector<string> res;
    int num;
    vector<string> generateParenthesis(int n) {
        num=n;
        solve(0,0,"");
        return res;
    }
    
    void solve(int left, int right, string str)
    {
        if(left==num && right==num) // base case
        {
            res.push_back(str);
            return;
        }
        if(left < num) // left parenthesis can be added
            solve(left+1,right,str+'(');
        if(right < left) // right parenthesis can be added
            solve(left,right+1,str+')');
    }
};