class Solution {
public:
    string arrangeWords(string text) {
        // word-length -> { word }
        map<int, vector<string>> mp; 
        string word = "";
        // to extract the last word easily
        text += " "; 
        for(char ch: text)
        {
            if(ch == ' ')
            {
                mp[word.length()].push_back(word);
                word = "";
            }
            else
                word += tolower(ch);
        }
        // restore the original text string
        text.pop_back();

        string ans = "";
        for(auto& [len, words]: mp)
            for(string& word: words)
                ans += word + " ";
        // remove the last whitespace
        ans.pop_back();
        // convert the first char of the first word to uppercase
        ans[0] = toupper(ans[0]);

        return ans;
    }
};