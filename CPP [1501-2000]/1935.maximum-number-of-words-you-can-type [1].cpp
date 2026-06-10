class Solution {
public:
    bool canBeTyped(string word, vector<bool>& broken){
        for(char ch: word)
            if(broken[ch - 'a'])
                return false;
        return true;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for(char ch: brokenLetters)
            broken[ch - 'a'] = true;
        string word = "";
        int count = 0;
        for(char ch: text)
        {
            if(ch == ' ')
            {
                if(canBeTyped(word, broken))
                    count++;
                word = "";
            }
            else
                word += ch;
        }
        if(canBeTyped(word, broken))
            count++;
        return count;
    }
};