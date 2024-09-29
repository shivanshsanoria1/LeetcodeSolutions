class AllOne {
private:
    // key -> freq
    unordered_map<string, int> mp;
    // {freq, key}
    set<pair<int, string>> s;

public:
    AllOne() {
        this->mp.clear();
        this->s.clear();
    }
    
    // T.C.=O(log(n))
    void inc(string key) {
        if(mp.find(key) == mp.end())
        {
            mp[key] = 1;
            s.insert({1, key});
            return;
        }

        int oldFreq = mp[key];
        auto itr = s.find({oldFreq, key});
        
        mp[key]++;
        s.erase(itr);
        s.insert({oldFreq + 1, key});
    }
    
    // T.C.=O(log(n))
    void dec(string key) {
        int oldFreq = mp[key];
        auto itr = s.find({oldFreq, key});
        
        if(--mp[key] == 0)
            mp.erase(key);
        
        s.erase(itr);
        if(--oldFreq > 0)
            s.insert({oldFreq, key});
    }
    
    // T.C.=O(1)
    string getMaxKey() {
        return s.empty() ? "" : s.rbegin()->second;
    }
    
    // T.C.=O(1)
    string getMinKey() {
        return s.empty() ? "" : s.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */