class Solution {
public:
    // T.C.=O(n + 26), S.C.=O(26)
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> firstIdx(26, -1);
        vector<int> lastIdx(26, -1);
        int n=s.length();

        for(int i=0; i<n; i++)
            if(firstIdx[s[i] - 'a'] == -1)
                firstIdx[s[i] - 'a'] = i;
        
        for(int i=n-1; i>=0; i--)
            if(lastIdx[s[i] - 'a'] == -1)
                lastIdx[s[i] - 'a'] = i;
        
        int maxLen = -1;
        for(int i=0; i<26; i++)
            maxLen = max(maxLen, lastIdx[i] - firstIdx[i] - 1);
        
        return maxLen;
    }
};