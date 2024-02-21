class LRUCache {
private:
    unordered_map<int, pair<int, int>> mp1; // key -> {value, time}
    unordered_map<int, int> mp2; // time -> key
    int time;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        mp1.clear();
        mp2.clear();
        time = 0;
    }
    
    int get(int key) {
        time++;

        if(mp1.find(key) == mp1.end()) // key not found in map
            return -1;

        // find old time of key in map1
        int oldTime = mp1[key].second;
        // delete the entry with oldTime in map2 
        mp2.erase(oldTime);
        // add a new entry in map2 with curr time
        mp2[time] = key;
        // update the time with curr time in map1
        mp1[key].second = time;
        return mp1[key].first;
    }
    
    void put(int key, int value) {
        time++;

        if(mp1.find(key) != mp1.end()) // key found in map
        {
            // find old time of key in map1
            int oldTime = mp1[key].second;
            // delete the entry with oldTime in map2 
            mp2.erase(oldTime);
            // add a new entry in map2 with curr time
            mp2[time] = key;
            // update the time with curr time in map1
            mp1[key].second = time;
            // update the value with new value in map1
            mp1[key].first = value;
            return;
        }

        if(mp1.size() == cap) // capcity is reached
        {
            // find the min-time entry in map2
            auto it = min_element(mp2.begin(), mp2.end(), 
            [](const auto& a, const auto& b) { return a.first < b.first; });
            // corresponding key for map1
            int key1 = it->second;
            // delete the min-time entry from map2
            mp2.erase(it);
            // delete the corresponding entry from map1
            mp1.erase(key1);
        }
        // add a new entry in map2 with curr time
        mp2[time] = key;
        // add a new entry in map1 with new value and curr time
        mp1[key] = {value, time};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */