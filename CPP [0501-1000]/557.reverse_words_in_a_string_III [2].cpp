class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        for(char ch: s)
        {
            if(ch == ' ')
            {
                reverse(word.begin(), word.end()); // reverse the word
                ans += word + " ";
                word = ""; // reset the word
            }   
            else
                word += ch;
        }
        reverse(word.begin(), word.end()); // reverse the last word
        ans += word;
        return ans;
    }
};