class Solution {
public:
    // T.C.=O(n + 26*log(26)), S.C.=O(26)
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char ch: word)
            freq[ch - 'a']++;
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        int presses = 0;
        for(int i=0; i<26 && freq[i] > 0; i++)
            presses += freq[i] * (i/8 + 1);

        return presses;
    }
};