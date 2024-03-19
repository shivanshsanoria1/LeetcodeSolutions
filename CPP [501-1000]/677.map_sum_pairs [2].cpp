class MapSum {
private:
    // string -> val
    unordered_map<string, int> stringMap;
    // prefix -> val
    unordered_map<string, int> prefixMap;

public:
    MapSum() {
        this->stringMap.clear();
        this->prefixMap.clear();
    }
    
    // T.C.=O(n)
    // n: length of 'key'
    void insert(string key, int val) {
        // old value of 'key' if it is already present in map and 0 otherwise
        int oldVal = stringMap.find(key) != stringMap.end() ? stringMap[key] : 0;

        // fix the values of all the prefixes of 'key'
        for(int i=0; i<key.length(); i++)
            prefixMap[key.substr(0, i+1)] += val - oldVal;

        // insert the latest key-value pair
        stringMap[key] = val;
    }
    
    // T.C.=O(1)
    int sum(string prefix) {
        return prefixMap[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */