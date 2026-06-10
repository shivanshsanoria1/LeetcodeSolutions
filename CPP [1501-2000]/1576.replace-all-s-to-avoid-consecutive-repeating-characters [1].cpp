class Solution {
public:
    string modifyString(string s) {
        int n=s.length();
        for(int i=0; i<n; i++)
        {
            if(s[i] != '?')
                continue;
            char prevCh = i == 0 ? '#' : s[i-1];
            char nextCh = i == n-1 ? '#' : s[i+1]; 
            for(char ch='a'; ch<='z'; ch++)
                if(ch != prevCh && ch != nextCh)
                    s[i] = ch;
        }
        return s;
    }
};