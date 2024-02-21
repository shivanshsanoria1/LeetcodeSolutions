class Solution {
public:
    bool isValidWord(string word){
        int n=word.length();
        if(n == 0)
            return false;
        int hyphenCount = 0;
        for(int i=0; i<word.length(); i++)
        {
            // digits not allowed
            if(word[i] >= '0' && word[i] <= '9')
                return false;
            // at most 1 hyphen allowed and it must be preceeded and followed by a lowercase letter
            else if(word[i] == '-')
            {
                if(i-1 >= 0 && i+1 < n && islower(word[i-1]) && islower(word[i+1]))
                {
                    hyphenCount++;
                    if(hyphenCount > 1)
                        return false;
                }
                else
                    return false;
            }
            // at most 1 punctuation allowed and it must be at the end of the word
            else if(word[i] == '!' || word[i] == '.' || word[i] == ',')
            {
                if(i < n-1)
                    return false;
            }
        }
        return true;
    }

    int countValidWords(string sentence) {
        int count = 0;
        string word = "";
        for(char ch: sentence)
        {
            if(ch == ' ')
            {
                if(isValidWord(word))
                    count++;
                word = ""; // reset the word
            }
            else
                word += ch;
        }
        if(isValidWord(word)) // check the last word
            count++;
        return count;
    }
};