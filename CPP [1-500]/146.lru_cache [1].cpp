class LRUCache {
private:
    unordered_map<int, pair<int, int>> mp1; // key -> {value, time}
    map<int, int> mp2; // time -> key
    int time;
    int capacity;

public:
    LRUCache(int capacity) {
        time = 0;
        this->capacity = capacity;
        mp1.clear();
        mp2.clear();
    }
    
    int get(int key) {
        time++;

        if(mp1.find(key) == mp1.end()) // key not found in map1
            return -1;
        
        /* ------ SEARCH ------ */

        // find old time of key in map1
        int oldTime = mp1[key].second;
        // delete the entry with oldTime from map2 
        mp2.erase(oldTime);
        // add a new entry with curr time in map2 
        mp2[time] = key;
        // update the time with curr time in map1
        mp1[key].second = time;
        // return the value of 'key' from map1
        return mp1[key].first;
    }
    
    void put(int key, int value) {
        time++;

        /* ------ UPDATE ------ */

        if(mp1.find(key) != mp1.end()) // key found in map1
        {
            // find old time of key in map1
            int oldTime = mp1[key].second;
            // delete the entry with oldTime from map2 
            mp2.erase(oldTime);
            // add a new entry with curr time in map2 
            mp2[time] = key;
            // update the value with new value and the time with curr time in map1
            mp1[key] = {value, time};
            return;
        }

        /* ------ DELETE ------ */

        if(mp1.size() == capacity) // capcity is reached
        {
            // iterator to min-time entry in map2
            auto itr = mp2.begin();
            // corresponding key for map1
            int key1 = itr->second;
            // delete the min-time entry from map2
            mp2.erase(itr);
            // delete the corresponding entry from map1
            mp1.erase(key1);
        }

        /* ------ INSERT ------ */

        // add a new entry with curr time in map2
        mp2[time] = key;
        // add a new entry with new value and curr time in map1
        mp1[key] = {value, time};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */