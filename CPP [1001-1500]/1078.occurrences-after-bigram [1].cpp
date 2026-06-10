class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        string word = "";
        for(char ch: text)
        {
            if(ch == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
                word += ch;
        }
        words.push_back(word);

        vector<string> ans;
        for(int i=2; i<words.size(); i++)
            if(words[i-2] == first && words[i-1] == second)
                ans.push_back(words[i]);
        return ans;
    }
};