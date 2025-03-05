class Solution {
public:
    // T.C.=O(n + 26), S.C.=O(26)
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        
        int maxOddFreq = 0;
        int minEvenFreq = s.length();
        
        for(int i=0; i<26; i++)
        {
            if(freq[i] == 0)
                continue;

            if(freq[i] % 2 == 1)
                maxOddFreq = max(maxOddFreq, freq[i]);
            else
                minEvenFreq = min(minEvenFreq, freq[i]);
        }

        return maxOddFreq - minEvenFreq;
    }
};