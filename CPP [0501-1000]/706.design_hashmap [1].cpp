class MyHashMap {
// Time inefficient and Space efficient soln.
private:
    // {key, value}
    vector<pair<int, int>> mp; 

public:
    MyHashMap() {
        this->mp.clear();
    }
    
    // T.C.=O(n)
    void put(int key, int value) { 
        for(int i=0; i<mp.size(); i++)
            // key found
            if(mp[i].first == key) 
            {
                // update the value corresponding to the key
                mp[i].second = value; 
                return;
            }

        // key not found
        // push the key-value pair in the map
        mp.push_back({key, value}); 
    }
    
    // T.C.=O(n)
    int get(int key) {
        for(auto it: mp)
            // key found
            if(it.first == key)
                return it.second;
        
        // key not found
        return -1; 
    }
    
    // T.C.=O(n)
    void remove(int key) { 
        int idx = -1;

        for(int i=0; i<mp.size(); i++)
            // key found
            if(mp[i].first == key)
            {
                idx = i;
                break;
            }

        // key not found in map
        if(idx == -1) 
            return;

        // move each element after the index idx to their prev index,
        // element at index idx is lost
        for(int i=idx; i<mp.size()-1; i++)
            mp[i] = mp[i+1];
            
        // pop the last element from map
        mp.pop_back(); 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */