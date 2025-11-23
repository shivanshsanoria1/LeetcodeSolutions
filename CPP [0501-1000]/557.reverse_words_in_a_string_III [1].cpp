class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n=s.length();
        for(int i=0; i<n; i++)
        {
            string word = "";
            while(i<n && s[i] != ' ') // find a word
            {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end()); // reverse the word
            if(!ans.empty()) // don't add space before the first word
                ans += " ";
            ans += word;
        }
        return ans;
    }
};