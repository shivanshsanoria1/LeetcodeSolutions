class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        unordered_set<int> freqSet;
        int count = 0;
        for(int i=0; i<26; i++)
        {
            while(freq[i] > 0 && freqSet.find(freq[i]) != freqSet.end())
            {
                freq[i]--;
                count++;
            }
            freqSet.insert(freq[i]);
        }
        return count;
    }
};