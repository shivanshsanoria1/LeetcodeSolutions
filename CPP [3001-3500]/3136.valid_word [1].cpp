class Solution {
private:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    bool isValid(string word) {
        if(word.length() < 3)
            return false;

        bool digit = false;
        bool vowel = false;
        bool consonant = false;

        for(char ch: word)
        {
            if(ch >= '0' && ch <= '9')
                digit = true;
            else if(ch >= 'a' && ch <= 'z')
            {
                if(isVowel(ch))
                    vowel = true;
                else
                    consonant = true;
            }
            else if(ch >= 'A' && ch <= 'Z')
            {
                if(isVowel(ch))
                    vowel = true;
                else
                    consonant = true;
            }
            else
                return false;
        }

        return vowel && consonant;
    }
};