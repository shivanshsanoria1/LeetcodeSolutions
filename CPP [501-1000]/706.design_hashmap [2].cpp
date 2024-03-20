class MyHashMap {
// Time efficient and Space inefficient soln.
private:
    // i is key and mp[i] is value
    // mp[i] = -1 indicates that key-value pair is not present in map
    vector<int> mp;

public:
    MyHashMap() {
        // vector of size 1,000,001 filled with -1's
        this->mp.resize(int(1e6 + 1), -1);
    }
    
    // T.C.=O(1)
    void put(int key, int value) {
        mp[key] = value;
    }
    
    // T.C.=O(1)
    int get(int key) { 
        return mp[key];
    }
    
    // T.C.=O(1)
    void remove(int key) { 
        mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */