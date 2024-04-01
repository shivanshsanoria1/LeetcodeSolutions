class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordLen = 0;

        for(int i=s.length()-1; i>=0; i--)
        {
            // char of the last word
            if(s[i] != ' ')
                wordLen++;
            // found the space before the last word
            else if(wordLen > 0)
                break;
        }

        return wordLen;
    }
};