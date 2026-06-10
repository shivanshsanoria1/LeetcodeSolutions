class WordFilter {
private:
    // prefix and suffix pair -> index
    unordered_map<string, int> mp;

public:
    WordFilter(vector<string>& words) {
        mp.clear();

        for(int i=0; i<words.size(); i++)
        {
            int n=words[i].size();
            // generate all possible pairs of prefix and suffix
            for(int j=1; j<=n; j++)
            {
                string prefix = words[i].substr(0, j);
                for(int k=0; k<n; k++)
                {
                    string suffix = words[i].substr(k);
                    mp[prefix + "#" + suffix] = i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string hash = pref + "#" + suff;
        return mp.find(hash) != mp.end() ? mp[hash] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */