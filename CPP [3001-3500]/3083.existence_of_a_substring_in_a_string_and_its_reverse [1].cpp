class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    bool isSubstringPresent(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        int n=s.length();
        for(int i=0; i<n-1; i++)
            for(int j=0; j<n-1; j++)
                if(s.substr(i, 2) == rev_s.substr(j, 2))
                    return true;
                    
        return false;
    }
};