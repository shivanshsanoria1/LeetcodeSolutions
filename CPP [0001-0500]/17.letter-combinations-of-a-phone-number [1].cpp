class Solution {
public:
    void solve(string& digits, int dig_index, vector<string>& alpha, vector<string>& ans, string& curr)
    {
        if(dig_index == digits.size())
        {
            ans.push_back(curr);
            return;
        }
        int alpha_index = digits[dig_index]-'0';
        for(int i=0; i < alpha[alpha_index].length(); i++)
        {
            curr += alpha[alpha_index][i];
            solve(digits, dig_index+1, alpha, ans, curr);
            curr.pop_back();
        }  
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "")
            return ans;
        vector<string> alpha(10,"");
        alpha[2]="abc";
        alpha[3]="def";
        alpha[4]="ghi";
        alpha[5]="jkl";
        alpha[6]="mno";
        alpha[7]="pqrs";
        alpha[8]="tuv";
        alpha[9]="wxyz";
        string s="";
        solve(digits,0,alpha,ans,s);
        return ans;
    }
};