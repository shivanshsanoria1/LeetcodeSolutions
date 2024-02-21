class Trie {
private:
    unordered_set<string> dict;

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
        for(string word: dict)
        {
            if(prefix.length() > word.length())
                continue;
            int count = 0;
            for(int i=0; i<prefix.length(); i++)
            {
                if(prefix[i] == word[i])
                    count++;
                else
                    break;
            }
            if(count == prefix.length())
                return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */