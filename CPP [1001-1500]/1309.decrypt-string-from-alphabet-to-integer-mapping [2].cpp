class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        int n=s.length();
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]!='#')
                ans+=(char)(s[i]-'0'-1)+'a';
            else
            {
                int curr=10*(s[i-2]-'0')+(s[i-1]-'0');
                ans+=(char)(curr-10)+'j';
                i=i-2;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};