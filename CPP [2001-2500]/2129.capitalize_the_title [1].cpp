class Solution {
public:
    void modifyWord(string& word){
        int n=word.length();
        if(n == 1)
        {
            word[0] = tolower(word[0]);
            return;
        }
        if(n == 2)
        {
            word[0] = tolower(word[0]);
            word[1] = tolower(word[1]);
            return;
        }
        word[0] = toupper(word[0]);
        for(int i=1; i<n; i++)
            word[i] = tolower(word[i]);
    }

    string capitalizeTitle(string title) {
        string ans = "";
        string word = "";
        for(char ch: title)
        {
            if(ch == ' ')
            {
                modifyWord(word);
                ans += word + " ";
                word = "";
            }
            else
                word += ch;
        }
        modifyWord(word);
        ans += word;
        return ans;
    }
};