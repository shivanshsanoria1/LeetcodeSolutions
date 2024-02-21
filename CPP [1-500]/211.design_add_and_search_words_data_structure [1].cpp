class WordDictionary {
private:
    unordered_map<int, unordered_map<int, unordered_set<string>>> dict; // word length -> { hash -> {word} }

public:
    WordDictionary() {
        dict.clear();
    }
    
    void addWord(string word) {
        dict[word.length()][getHash(word)].insert(word);
    }
    
    bool search(string word) {
        int dots = 0;
        for(char ch: word) // count the dots in word
            if(ch == '.')
                dots++;
        int minHash = getHash(word) + 1*dots; // assuming all dots are a's
        int maxHash = getHash(word) + 26*dots; // assuming all dots are z's
        for(int hash = minHash; hash <= maxHash; hash++)
            for(string w: dict[word.length()][hash])
            {
                bool found = true;
                for(int i=0; i<word.length(); i++)
                {
                    if(word[i] == '.')
                        continue;
                    if(word[i] != w[i])
                    {
                        found = false;
                        break;
                    }
                }
                if(found)
                    return true;
            }
        return false;
    }

    int getHash(string& str){
        int hash = 0;
        for(char ch: str)
        {
            if(ch == '.')
                continue;
            hash += ch - 'a' + 1;
        }
        return hash;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */