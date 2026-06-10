class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countSubstrings(string s, char c) {
        int n=s.length();
        long long int count = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] != c)
                continue;
            for(int j=i; j<n; j++)
                if(s[j] == c)
                    count++;
        }
        return count;
    }
};