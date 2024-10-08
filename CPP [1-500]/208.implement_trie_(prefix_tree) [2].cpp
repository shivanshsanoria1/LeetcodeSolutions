class Trie {
private:
    unordered_set<string> dict;
    unordered_set<string> prefixDict;

public:
    Trie() {
        this->dict.clear();
        this->prefixDict.clear();
    }
    
    void insert(string word) {
        dict.insert(word);

        // insert every prefix of 'word' in prefix-dictionary
        string prefix = "";
        for(char ch: word)
        {
            prefix += ch;
            prefixDict.insert(prefix);
        }
    }
    
    bool search(string word) {
        return dict.find(word) != dict.end();
    }
    
    bool startsWith(string prefix) {
        return prefixDict.find(prefix) != prefixDict.end();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */