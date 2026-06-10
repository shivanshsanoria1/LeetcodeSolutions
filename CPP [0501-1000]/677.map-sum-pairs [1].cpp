class MapSum {
private:
    // string -> val
    unordered_map<string, int> mp;

    // returns true if s2 is a prefix of s1
    bool isPrefix(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();
        // prefix cannot be longer than the main string
        if(n1 < n2)
            return false;
        for(int i=0; i<n2; i++)
            if(s1[i] != s2[i])
                return false;
        return true;
    }

public:
    MapSum() {
        this->mp.clear();
    }
    
    // T.C.=O(1)
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    // T.C.=O(n*l)
    // n: number of keys in map, l: length of prefix
    int sum(string prefix) {
        int sum = 0;
        for(auto [key, val]: mp)
            if(isPrefix(key, prefix))
                sum += mp[key];
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */