class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        int n=s.length();
        for(int i=0; i<n-2; i++)
        {
            int curr=s[i]-'0';
            if(s[i+2]=='#')
            {
                curr=10*(s[i]-'0')+(s[i+1]-'0');
                ans+=(char)(curr-10)+'j';
                i=i+2;
            }
            else
                ans+=(char)(curr-1)+'a';
        }
        if(s[n-1]=='#')
            return ans;
        if(s[n-2]!='#')
            ans+=(char)(s[n-2]-'0'-1)+'a'; //add the 2nd last char to ans
        ans+=(char)(s[n-1]-'0'-1)+'a'; //add the last char to ans
        return ans;
    }
};