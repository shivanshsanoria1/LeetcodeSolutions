class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n=s.length(), c=0;
        for(int i=0; i<n; i++)
            if(s[i]==letter)
                c++;
        return (c*100)/n;
    }
};