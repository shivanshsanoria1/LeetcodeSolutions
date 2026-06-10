class Solution {
public:
    // T.C.=O(26 + n*m), S.C.=O(26)
    // n: size of words[], m: max length of a word in words[]
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> isAllowed(26, false);
        for(char ch: allowed)
            isAllowed[ch - 'a'] = true;
        
        int invalid = 0;
        for(string& word: words)
            for(char ch: word)
                if(!isAllowed[ch - 'a'])
                {
                    invalid++;
                    break;
                }
        
        return words.size() - invalid;
    }
};