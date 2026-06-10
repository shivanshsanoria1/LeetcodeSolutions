class MagicDictionary {
private:
    unordered_set<string> dict;

public:
    MagicDictionary() {
        dict.clear();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string& word: dictionary)
            dict.insert(word);
    }
    
    bool search(string searchWord) {
        for(string word: dict)
        {
            if(word.length() != searchWord.length())
                continue;
            int count = 0;
            for(int i=0; i<searchWord.length(); i++)
            {
                if(word[i] != searchWord[i])
                    count++;
                if(count > 1)
                    break;
            }
            if(count == 1)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */