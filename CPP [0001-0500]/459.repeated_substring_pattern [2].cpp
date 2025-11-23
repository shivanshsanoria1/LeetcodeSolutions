class Solution {
public:
    bool repeatedSubstringPattern(string s) { // T.C.=O(n*sqrt(n)), S.C.=O(n)
        int n=s.length();
        for(int i=0; i<n/2; i++)
        {
            if(n % (i+1) != 0)
                continue;
            string s2 = "";
            for(int j=0; j < n/(i+1); j++)
                s2 += s.substr(0, i+1);
            if(s == s2)
                return true;
        }
        return false;
    }
};