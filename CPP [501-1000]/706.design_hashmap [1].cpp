class MyHashMap {
// Time inefficient and Space efficient soln.
private:
    vector<pair<int, int>> mp; // {key, value}

public:
    MyHashMap() {
        mp.clear();
    }
    
    void put(int key, int value) { // T.C.=O(n)
        for(int i=0; i<mp.size(); i++)
            if(mp[i].first == key) // key found
            {
                mp[i].second = value; // update the value corresponding to the key
                return;
            }
        // key not found
        mp.push_back({key, value}); // push the key-value pair in the map
    }
    
    int get(int key) { // T.C.=O(n)
        for(auto it: mp)
            if(it.first == key) // key found
                return it.second; // return the value corresponding to the key
        return -1; // key not found
    }
    
    void remove(int key) { // T.C.=O(n)
        int idx = -1;
        for(int i=0; i<mp.size(); i++)
            if(mp[i].first == key) // key found
            {
                idx = i;
                break;
            }
        if(idx == -1) // key not found in map
            return;
        // move each element after the index idx to their prev index
        // element at index idx is lost
        for(int i=idx; i<mp.size()-1; i++)
            mp[i] = mp[i+1];
        mp.pop_back(); // pop the last element from map
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */