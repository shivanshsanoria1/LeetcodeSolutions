class MyHashMap {
// Time efficient and Space inefficient soln.
private:
    // i is key and mp[i] is value
    // mp[i] = -1 indicates that key-value pair is not present in map
    vector<int> mp;

public:
    MyHashMap() {
        mp.resize(1000001, -1); // vector of size 1,000,001 filled with -1's
    }
    
    void put(int key, int value) { // T.C.=O(1)
        mp[key] = value;
    }
    
    int get(int key) { // T.C.=O(1)
        return mp[key];
    }
    
    void remove(int key) { // T.C.=O(1)
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