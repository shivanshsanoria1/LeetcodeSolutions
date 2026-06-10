class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans="";
        int i=0;
        while(i < s.length() && k > 0)
        {
            if(s[i]==' ')
                k--;
            ans+=s[i];
            i++;
        }
        int n=ans.length();
        return ans[n-1]==' ' ? ans.substr(0,n-1) : ans; //if last char is ' ' then don't include it in ans
    }
};