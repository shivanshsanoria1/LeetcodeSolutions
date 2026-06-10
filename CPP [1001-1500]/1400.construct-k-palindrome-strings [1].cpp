class Solution {
public:
    // T.C.=O(n), S.C.=O(26)
    bool canConstruct(string s, int k) {
        if(k > s.length())
            return false;
        
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        
        int oddFreqCount = 0;
        for(int i=0; i<26; i++)
            if(freq[i] % 2 == 1)
                oddFreqCount++;
        
        return oddFreqCount > k ? false : true;
    }
};