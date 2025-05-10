class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
public:
    // T.C.=O(n + 26), S.C.=O(26)
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for(char ch: s)
           freq[ch - 'a']++;

        int maxFreq1 = 0, maxFreq2 = 0;
        for(int i=0; i<26; i++)
        {
            char ch = i + 'a';

            if(isVowel(ch))
                maxFreq1 = max(maxFreq1, freq[i]);
            else
                maxFreq2 = max(maxFreq2, freq[i]);
        }

        return maxFreq1 + maxFreq2;
    }
};