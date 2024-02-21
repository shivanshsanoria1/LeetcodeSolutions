class Solution {
public:
    bool isPrefix(string s1, string s2) //returns true if s2 is a prefix of s1
    {
        int n1=s1.length(), n2=s2.length();
        if(n1 < n2) //s1 cannot be smaller than s2
            return false;
        for(int i=0; i<n2; i++)
            if(s1[i] != s2[i])
                return false;
        return true;
    }
    
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        for(auto it: words)
            if(isPrefix(it,pref)==true)
                c++;
        return c;
    }
};