class Solution {
public:
    // T.C.=O(n), S.C.=O(2*26)
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);

        for(char ch: word)
        {
            if(islower(ch))
                lower[ch - 'a'] = true;
            else
                upper[ch - 'A'] = true;
        }

        int count = 0;

        for(int i=0; i<26; i++)
            if(lower[i] && upper[i])
                count++;
        
        return count;
    }
};