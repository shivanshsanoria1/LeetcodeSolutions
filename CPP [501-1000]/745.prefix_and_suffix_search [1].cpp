class WordFilter {
private:
    vector<string> dict;

    bool prefixFound(string& word, string& prefix) {
        int n=prefix.length();
        if(n > word.size())
            return false;
        for(int i=0; i<n; i++)
            if(prefix[i] != word[i])
                return false;
        return true;
    }

    bool suffixFound(string& word, string& suffix) {
        int n=suffix.length();
        if(n > word.length())
            return false;
        for(int i=0; i<n; i++)
            if(suffix[i] != word[word.length() - n + i])
                return false;
        return true;
    }

public:
    WordFilter(vector<string>& words) {
        for(int i=0; i<words.size(); i++)
            dict.push_back(words[i]);
    }
    
    int f(string pref, string suff) {
        for(int i=dict.size()-1; i>=0; i--)
            if(prefixFound(dict[i], pref) && suffixFound(dict[i], suff))
                return i;
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */