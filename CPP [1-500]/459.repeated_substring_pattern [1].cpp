class Solution {
public:
    // returns true if s2 can be appended to itself multiple times to form s1
    bool check(string &s1, string &s2){
        int n1=s1.length(), n2=s2.length();
        if(n1 % n2 != 0)
            return false;
        for(int i=0; i<n1; i++)
            if(s1[i] != s2[i % n2])
                return false;
        return true;
    }

    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int i=0; i<n/2; i++)
        {
            string subStr = s.substr(0, i+1);
            if(check(s, subStr))
                return true;
        }
        return false;
    }
};