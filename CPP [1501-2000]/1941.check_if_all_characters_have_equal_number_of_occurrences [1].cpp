class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        int f = -1;
        for(int i=0; i<26; i++)
        {
            if(freq[i] == 0) // skip the 0 freqs
                continue;
            if(f == -1) // found the first non-zero freq
                f = freq[i];
            else if(f != freq[i]) // non-matching freqs found
                return false;
        }
        return true;
    }
};