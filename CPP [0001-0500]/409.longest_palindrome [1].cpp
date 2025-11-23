class Solution {
public:
    // T.C.=O(n), S.C.=O(2*26)
    int longestPalindrome(string s) {
        vector<int> freqLower(26, 0);
        vector<int> freqUpper(26, 0);

        for(char ch: s)
        {
            if(islower(ch))
                freqLower[ch - 'a']++;
            else
                freqUpper[ch - 'A']++;
        }

        int evenFreqSum = 0;
        bool oddFreqFound = false;

        for(int i=0; i<26; i++)
        {
            if(freqLower[i] % 2 == 0)
                evenFreqSum += freqLower[i];
            else
            {
                evenFreqSum += freqLower[i] - 1;
                oddFreqFound = true;
            }
            
            if(freqUpper[i] % 2 == 0)
                evenFreqSum += freqUpper[i];
            else
            {
                evenFreqSum += freqUpper[i] - 1;
                oddFreqFound = true;
            }
        }

        return oddFreqFound ? 1 + evenFreqSum : evenFreqSum;
    }
};