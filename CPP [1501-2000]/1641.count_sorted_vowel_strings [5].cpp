class Solution {
public:
    int solve(int n, vector<char>& vow, int index, string& s)
    {
        if(s.length() == n)
            return 1;
        int sum=0;
        for(int i=index; i<5; i++)
        {
            s += vow[i]; //add the curr char to string s
            sum += solve(n,vow,i,s);
            s.pop_back(); //pop back the curr char from string s
        }
        return sum;
    }
    
    int countVowelStrings(int n) { //T.C.=O(5^n) , S.C.=O(1) , backtracking
        vector<char> vow= {'a','e','i','o','u'};
        string s="";
        return solve(n,vow,0,s);
    }
};