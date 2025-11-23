class WordFilter {
private:
    // prefix -> { index of the word which has this prefix }
    unordered_map<string, unordered_set<int>> prefixMap;
    // suffix -> { index of the word which has this suffix }
    unordered_map<string, unordered_set<int>> suffixMap;

public:
    WordFilter(vector<string>& words) {
        prefixMap.clear();
        suffixMap.clear();

        for(int i=0; i<words.size(); i++)
        {
            int n=words[i].size();

            for(int j=1; j<=n; j++)
                prefixMap[words[i].substr(0, j)].insert(i);

            for(int j=0; j<n; j++)
                suffixMap[words[i].substr(j)].insert(i);
        }
    }
    
    int f(string pref, string suff) {
        // prefix not found
        if(prefixMap.find(pref) == prefixMap.end())
            return -1;
        // suffix not found
        if(suffixMap.find(suff) == suffixMap.end())
            return -1;

        unordered_set<int> prefixIdxSet = prefixMap[pref];
        unordered_set<int> suffixIdxSet = suffixMap[suff];

        int maxIdx = -1;
        // max index in prefix-index-set which is also present in suffix-index-set
        for(int idx: prefixIdxSet)
            if(suffixIdxSet.find(idx) != suffixIdxSet.end())
                maxIdx = max(maxIdx, idx);
        // max index in suffix-index-set which is also present in prefix-index-set
        for(int idx: suffixIdxSet)
            if(prefixIdxSet.find(idx) != prefixIdxSet.end())
                maxIdx = max(maxIdx, idx);
        return maxIdx;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */