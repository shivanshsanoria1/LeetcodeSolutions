class Solution {
public:
    vector<string> printVertically(string s) {
        // extract the words into the 'words' vector
        vector<string> words;
        string word = "";
        int maxWordLength = 0;
        s += " ";
        for(char ch: s)
        {
            if(ch == ' ')
            {
                words.push_back(word);
                maxWordLength = max(maxWordLength, (int)word.length());
                word = "";
            }
            else
                word += ch;
        }
        s.pop_back();

        vector<string> ans;
        for(int j=0; j<maxWordLength; j++)
        {
            string ansWord = "";
            for(string& word: words)
                ansWord += j < word.length() ? word[j] : ' ';

            // remove the trailing spaces
            while(ansWord.back() == ' ')
                ansWord.pop_back();

            ans.push_back(ansWord);
        }
        
        return ans;
    }
};