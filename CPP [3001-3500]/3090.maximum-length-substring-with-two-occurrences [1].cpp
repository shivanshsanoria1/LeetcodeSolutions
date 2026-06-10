class Solution {
public:
    // T.C.=O(n^2), S.C.=O(26)
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int maxLen = 0;
        for(int i=0; i<n; i++)
        {
            vector<int> freq(26, 0);
            for(int j=i; j<n; j++)
            {
                if(freq[s[j] - 'a'] >= 2)
                    break;
                freq[s[j] - 'a']++;
                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};