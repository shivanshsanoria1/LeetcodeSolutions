class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length(), c=0, flag=0;
        if(n==1)
            return 1;
        vector<int> count_lower(26,0), count_upper(26,0); // keeps track of freq. of lowercase and uppercase letters
        for(int i=0; i<n; i++)
        {
            if(s[i]>='a' && s[i]<='z') // lowercase
                count_lower[s[i]-'a']++;
            else // uppercase
                count_upper[s[i]-'A']++;
        }
        for(int i=0; i<26; i++)
        {
            if(count_lower[i]>0) // lowercase
            {
                if(count_lower[i]%2==0) // even freq.
                    c=c+count_lower[i];
                else // odd freq.
                {
                    c=c+count_lower[i]-1;
                    flag=1;
                }
            }
            if(count_upper[i]>0) // uppercase
            {
                if(count_upper[i]%2==0) // even freq.
                    c=c+count_upper[i];
                else // odd freq.
                {
                    c=c+count_upper[i]-1;
                    flag=1;
                }
            }
        }
        if(flag==1) // atleast 1 letter with odd freq. is found ,i.e., odd length palindrome 
            return c+1;
        return c; // even length palindrome
    }
};