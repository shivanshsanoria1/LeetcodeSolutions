class Solution {
public:
    // T.C.=O(d + s), S.C.=O(d + w)
    // d: length of 'dictionary', s: length of 'sentence', 
    // w: max length of a word 'sentence'
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        string word = "";
        string prefix = "";
        string ans = "";
        // to extract the last word
        sentence += " ";

        for(char ch: sentence)
        {
            if(ch == ' ')
            {
                // no prefix of curr-word found in dict
                if(prefix == "")
                    ans += word + " ";
                // smallest prefix of curr-word present in dict
                else
                    ans += prefix + " ";

                // reset the word and prefix
                word = "";
                prefix = "";
                
            }
            else
                word += ch;

            // smallest prefix corresponding to the curr-word found in dict
            if(prefix == "" && dict.find(word) != dict.end())
                prefix = word;
        }

        // restore back the original sentence
        sentence.pop_back();
        // remove the trailing space
        ans.pop_back();

        return ans;
    }
};