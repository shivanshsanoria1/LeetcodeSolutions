class Solution {
public:
    // T.C.=O(n1*log(n1) + n2*log(n2)), S.C.=O(1)
    bool isAnagram(string s, string t) {
        int n1=s.length(), n2=t.length();
        if(n1 != n2)
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<n1; i++)
            if(s[i] != t[i])
                return false;
        return true;
    }
};