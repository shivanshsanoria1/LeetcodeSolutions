class Solution {
private:
    void solve(vector<string>& dict, vector<string>& sentences, string& s, string& sentence, int i){
        if(i == s.length())
        {
            // remove the last space
            sentence.pop_back(); 

            sentences.push_back(sentence);

            // add back the last space
            sentence += " "; 
            
            return;
        }

        for(string& word: dict)
            if(s.substr(i, word.length()) == word)
            {
                sentence += word + " ";

                solve(dict, sentences, s, sentence, i + word.length());

                int len = word.length() + 1;
                // remove the curr word and space from curr str
                while(len--) 
                    sentence.pop_back();
            }
    }

public:
    // Backtracking
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sentences;
        string sentence = "";

        solve(wordDict, sentences, s, sentence, 0);

        return sentences;
    }
};