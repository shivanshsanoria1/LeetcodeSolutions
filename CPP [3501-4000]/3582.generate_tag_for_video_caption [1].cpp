class Solution {
private:
    vector<string> tokenize(string& s){
        vector<string> words;
        string word = "";

        s += " ";
        for(char ch: s)
        {
            if(ch == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
                word += ch;
        }
        s.pop_back();

        return words;
    }

    // removes all the non-alphabet chars from str
    string convertToAlpha(string str){
        string filteredStr = "";
        for(char ch: str)
            if(isalpha(ch))
                filteredStr += tolower(ch);
        
        return filteredStr;
    }

public:
    // T.C.=O(n), S.C.=O(n)
    string generateTag(string caption) {
        vector<string> words = tokenize(caption);

        string tag = "#";
        for(string word: words)
        {
            string filteredWord = convertToAlpha(word);
            if(filteredWord.length() == 0)
                continue;
            
            tag += tag == "#" ? tolower(filteredWord[0]) : toupper(filteredWord[0]);
            
            tag += filteredWord.substr(1);

            if(tag.length() > 100)
            {
                tag = tag.substr(0, 100);
                break;
            }
        }

        return tag;
    }
};