class Solution {
public:
    // T.C.=O(n), S.C.=O(3*26)
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        vector<bool> special(26, true);

        for(char ch: word)
        {
            if(islower(ch))
            {
                lower[ch - 'a'] = true;
                // a lowercase char is found after 
                // its corresponding uppercase char
                if(upper[ch - 'a'])
                    special[ch - 'a'] = false;
            }
            else
                upper[ch - 'A'] = true;
        }

        int count = 0;

        for(int i=0; i<26; i++)
            if(lower[i] && upper[i] && special[i])
                count++;
        
        return count;
    }
};