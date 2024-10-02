class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int maxLengthBetweenEqualCharacters(string s) { 
        int n=s.length();
        int maxLen = -1;
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                if(s[i] == s[j])
                    maxLen = max(maxLen, j-i-1);

        return maxLen;
    }
};