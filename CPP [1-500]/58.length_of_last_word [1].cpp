class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length(),c=0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]!=' ') // last word found
                c++;
            else if(c>0) // space before last word
                return c;
        }
        return c; // no space before last word
    }
};