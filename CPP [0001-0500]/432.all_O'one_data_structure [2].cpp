class AllOne {
private:
    // key -> freq
    unordered_map<string, int> mp1;
    // freq -> {key}
    map<int, unordered_set<string>> mp2;

public:
    AllOne() {
        this->mp1.clear();
        this->mp2.clear();
    }
    
    // T.C.=O(log(n))
    void inc(string key) {
        // key not found in mp1
        if(mp1.find(key) == mp1.end())
        {
            mp1[key] = 1;
            mp2[1].insert(key);
            return;
        }

        int oldFreq = mp1[key];

        mp1[key]++;

        mp2[oldFreq].erase(key);
        if(mp2[oldFreq].empty())
            mp2.erase(oldFreq);

        mp2[oldFreq + 1].insert(key);
    }
    
    // T.C.=O(log(n))
    void dec(string key) {
        int oldFreq = mp1[key];

        if(--mp1[key] == 0)
            mp1.erase(key);
        
        mp2[oldFreq].erase(key);
        if(mp2[oldFreq].empty())
            mp2.erase(oldFreq);

        if(--oldFreq > 0)
            mp2[oldFreq].insert(key);
    }
    
    // T.C.=O(1)
    string getMaxKey() {
        return mp1.empty() ? "" : *((mp2.rbegin()->second).begin());
    }
    
    // T.C.=O(1)
    string getMinKey() {
        return mp1.empty() ? "" : *((mp2.begin()->second).begin());
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