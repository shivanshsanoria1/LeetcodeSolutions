class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        string word = "";
        for(char ch: s)
        {
            if(ch == ' ')
            {
                if(word.length() > 0)
                    count++;
                word = "";
            }
            else
                word += ch;
        }
        return word.length() == 0 ? count : count + 1;
    }
};