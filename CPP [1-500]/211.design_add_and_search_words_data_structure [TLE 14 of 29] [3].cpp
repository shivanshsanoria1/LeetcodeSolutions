class WordDictionary {
private:
    // 10^9 + 7
    #define MOD 1000000007
    unordered_map<int, map<int, unordered_set<string>>> dict; // word length -> { hash -> {word} }

public:
    WordDictionary() {
        dict.clear();
    }
    
    void addWord(string word) {
        dict[word.length()][getHash(word)].insert(word);
    }
    
    bool search(string word) {
        int dot = 0;
        for(char ch: word)
            if(ch == '.')
                dot++;
        int minHash = getHash(word) % MOD; // assuming all dots are a's
        auto it = dict[word.length()].lower_bound(minHash);
        for(; it != dict[word.length()].end(); it++)
            for(string w: it->second)
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

    int getHash(string& str)
    {
        int hash = 0;
        for(char ch: str)
        {
            if(ch == '.')
                continue;
            hash = (hash * (ch - 'a' + 1)) % MOD;
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