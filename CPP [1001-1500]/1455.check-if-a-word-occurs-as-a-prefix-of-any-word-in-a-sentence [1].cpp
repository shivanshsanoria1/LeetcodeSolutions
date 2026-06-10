class Solution {
private:
    // returns true if s2 is a prefix of s1
    bool isPrefix(string& s1, string& s2){
        if(s1.length() < s2.length())
            return false;

        for(int i=0; i<s2.length(); i++)
            if(s1[i] != s2[i])
                return false;

        return true;
    }

public:
    // T.C.=O(n1*n2), S.C.=O(1)
    // n1: length of 'sentence', n2: length of 'searchWord'
    int isPrefixOfWord(string sentence, string searchWord) {
        string word = "";
        int wordCount = 0;
        sentence += " ";

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
        
        sentence.pop_back();

        return -1;
    }
};