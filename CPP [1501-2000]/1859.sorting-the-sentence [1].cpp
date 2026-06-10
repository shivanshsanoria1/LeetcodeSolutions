class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10, "");
        string word = "";
        for(char ch: s)
        {
            if(ch >= '0' && ch <='9')
            {
                words[ch - '0'] = word; // add the curr word to words[] 
                word = ""; // reset the word
                continue;
            }
            else if(ch == ' ')
                continue;
            word += ch;
        }
        string ans = "";
        for(int i=1; i<10; i++)
        {
            if(words[i].length() == 0) // no word to append
                continue;
            if(ans.length() == 0) // append the 1st word
                ans += words[i];
            else // append the remaining words
                ans += ' ' + words[i];
        }
        return ans;
    }
};