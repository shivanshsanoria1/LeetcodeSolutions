class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    // Greedy
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        
        int finalLen = 0;
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
                finalLen += freq[i] % 2 == 1 ? 1 : 2;
        
        return finalLen;
    }
};