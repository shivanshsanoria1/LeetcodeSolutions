class WordDictionary {
private:
    unordered_map<int, unordered_set<string>> dict; // word length -> {word}

public:
    WordDictionary() {
        dict.clear();
    }
    
    void addWord(string word) {
        dict[word.length()].insert(word);
    }
    
    bool search(string word) {
        for(string w: dict[word.length()])
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
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */