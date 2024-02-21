class Solution {
public:
    void solve(int n, vector<char>& vow, int index, string& s, vector<string>& ans)
    {
        if(s.length() == n)
        {
            ans.push_back(s);
            return;
        }
        for(int i=index; i<5; i++)
        {
            s += vow[i]; //add the curr char to string s
            solve(n,vow,i,s,ans);
            s.pop_back(); //pop back the curr char from string s
        }
    }
    
    int countVowelStrings(int n) { //T.C.=O(5^n) , backtracking
        vector<string> ans;
        vector<char> vow= {'a','e','i','o','u'};
        string s="";
        solve(n,vow,0,s,ans);
        return ans.size();
    }
};