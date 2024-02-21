class Solution {
public:
    string capitalizeTitle(string title) {
        string ans = "";
        string word = "";
        for(char ch: title)
        {
            if(ch == ' ')
            {
                ans += word + " ";
                word = "";
            }
            else
            {
                if(word.length() == 2)
                    word[0] = toupper(word[0]);
                word += tolower(ch);
            }
        }
        ans += word;
        return ans;
    }
};