class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        string word2 = "", word1 = ""; // equivalent to words[i-2], words[i-1]
        string word = ""; // equivalent to words[i]
        for(char ch: text)
        {
            if(ch == ' ')
            {
                if(word2 == first && word1 == second)
                    ans.push_back(word);
                word2 = word1;
                word1 = word;
                word = "";
            }
            else
                word += ch;
        }
        if(word2 == first && word1 == second)
            ans.push_back(word);
        return ans;
    }
};