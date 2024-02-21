class Trie {
private:
    set<string> dict;

public:
    Trie() {
        dict.clear();
    }
    
    void insert(string word) {
        dict.insert(word);
    }
    
    bool search(string word) {
        return dict.find(word) != dict.end() ? true : false;
    }
    
    bool startsWith(string prefix) {
        auto it = dict.lower_bound(prefix); // find the first word >= prefix
        if(it == dict.end()) // prefix not found in dict
            return false;
        string word = *it;
        for(int i=0; i<prefix.length(); i++) // compare prefix and word
            if(prefix[i] != word[i])
                return false;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */