class WordDictionary {
private:
    // word length -> { hash -> {word} }
    unordered_map<int, unordered_map<int, unordered_set<string>>> dict; 

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

    // returns true if strings s1 and s2 match
    // s1 and s2 are of equal length
    // s2 may contain dots ('.')
    bool stringMatch(string& s1, string& s2){
        for(int i=0; i<s2.length(); i++)
        {
            if(s2[i] == '.')
                continue;
            if(s2[i] != s1[i])
                return false;
        }

        return true;
    }

public:
    WordDictionary() {
        this->dict.clear();
    }
    
    void addWord(string word) {
        dict[word.length()][getHash(word)].insert(word);
    }
    
    bool search(string word) {
        // count the dots in word
        int dots = count(word.begin(), word.end(), '.');

        // assuming all dots are a's
        int minHash = getHash(word) + 1*dots; 
        // assuming all dots are z's
        int maxHash = getHash(word) + 26*dots; 

        for(int hash = minHash; hash <= maxHash; hash++)
            for(string w: dict[word.length()][hash])
                if(stringMatch(w, word))
                    return true;

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */