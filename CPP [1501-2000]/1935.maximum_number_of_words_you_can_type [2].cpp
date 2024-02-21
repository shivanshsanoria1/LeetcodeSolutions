class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for(char ch: brokenLetters)
            broken[ch - 'a'] = true;

        string word = "";
        bool canBeTyped = true; // initially assume the word can be typed
        int count = 0;
        for(char ch: text)
        {
            if(ch == ' ')
            {
                if(canBeTyped)
                    count++;
                canBeTyped = true;
                word = "";
            }
            else
            {
                if(broken[ch - 'a'])
                    canBeTyped = false;
                word += ch;
            }
        }
        if(canBeTyped)
            count++;
        return count;
    }
};