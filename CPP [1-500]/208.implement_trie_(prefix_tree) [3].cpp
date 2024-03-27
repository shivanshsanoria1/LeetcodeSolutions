class Trie {
private:
    set<string> dict;

public:
    Trie() {
        this->dict.clear();
    }
    
    void insert(string word) {
        dict.insert(word);
    }
    
    bool search(string word) {
        return dict.find(word) != dict.end() ? true : false;
    }
    
    bool startsWith(string prefix) {
        // iterator to the first word >= prefix
        auto itr = dict.lower_bound(prefix);

        // prefix not found in dict
        if(itr == dict.end()) 
            return false;
        
        // compare prefix and word
        string word = *itr;
        for(int i=0; i<prefix.length(); i++) 
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