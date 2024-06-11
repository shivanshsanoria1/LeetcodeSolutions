class Solution {
public:
    // T.C.=O(n + 26*log26), S.C.=O(4*26)
    bool closeStrings(string word1, string word2) {
        // both strings must be of same length
        if(word1.length() != word2.length())
            return false;

        vector<int> freq1(26, 0);
        vector<bool> char1(26, false);
        for(char ch: word1)
        {
            freq1[ch - 'a']++;
            char1[ch - 'a'] = true;
        }

        vector<int> freq2(26, 0);
        vector<bool> char2(26, false);
        for(char ch: word2)
        {
            freq2[ch - 'a']++;
            char2[ch - 'a'] = true;
        }
        
        // both strings must have the same chars
        for(int i=0; i<26; i++)
            if(char1[i] != char2[i])
                return false;

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // both strings must have the same set of freqs
        // so that their corresponding chars can be swapped 
        // to make the 2 strings equal
        for(int i=0; i<26; i++)
            if(freq1[i] != freq2[i])
                return false;
        
        return true;
    }
};