class Solution {
public:
    bool isPrefix(string& str, string& prefix){
        if(prefix.length() > str.length())
            return false;
        for(int i=0; i < prefix.length(); i++)
            if(str[i] != prefix[i])
                return false;
        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        string word = "";
        int wordCount = 0;
        for(char ch: sentence)
        {
            if(ch == ' ')
            {
                wordCount++;
                if(isPrefix(word, searchWord))
                    return wordCount;
                word = "";
            }
            else
                word += ch;
        }
        wordCount++;
        if(isPrefix(word, searchWord))
            return wordCount;
        return -1;
    }
};