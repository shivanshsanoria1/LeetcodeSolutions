class LFUCache {
private:
    unordered_map<int, vector<int>> mp1; // key -> {value, freq, time}
    map<int, map<int, int>> mp2; // freq -> {time, key}
    int time;
    int capacity;

public:
    LFUCache(int capacity) {
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

        // old freq and time of 'key'
        int oldFreq = mp1[key][1];
        int oldTime = mp1[key][2];
        // remove the entry with oldFreq and oldTime from map2
        mp2[oldFreq].erase(oldTime);
        // if the map mp2[oldFreq] becomes empty remove the entry oldFreq from map2
        if(mp2[oldFreq].empty())
            mp2.erase(oldFreq);
        // add a new entry with incremented freq and curr time in map2
        mp2[oldFreq + 1][time] = key;
        // increment the freq and update oldTime with curr time for 'key' in map1
        mp1[key][1] = oldFreq + 1;
        mp1[key][2] = time;
        // return the value of 'key' from map1
        return mp1[key][0];
    }
    
    void put(int key, int value) {
        time++;

        /* ------ UPDATE ------ */

        if(mp1.find(key) != mp1.end()) // key found in map1
        {
            // old freq and time of 'key'
            int oldFreq = mp1[key][1];
            int oldTime = mp1[key][2];
            // remove the entry with oldFreq and oldTime from map2
            mp2[oldFreq].erase(oldTime);
            // if the map mp2[oldFreq] becomes empty remove the entry oldFreq from map2
            if(mp2[oldFreq].empty())
                mp2.erase(oldFreq);
            // add a new entry with incremented freq and curr time in map2
            mp2[oldFreq + 1][time] = key;
            // update the value, increment the freq and update oldTime with curr time for 'key' in map1
            mp1[key] = {value, oldFreq + 1, time};
            return;
        }

        /* ------ DELETE ------ */

        if(mp1.size() == capacity) // capcity is reached
        {
            // iterator to min freq in map2
            auto itrFreq = mp2.begin();
            // iterator to min time in map2[min freq]
            auto itrTime = (itrFreq->second).begin();
            // min freq
            int minFreq = itrFreq->first;
            // key to be deleted
            int delKey = itrTime->second;
            // remove the entry with min time in mp2[minFreq]
            mp2[minFreq].erase(itrTime);
            // if the map mp2[minFreq] becomes empty remove the entry minFreq from map2
            if(mp2[minFreq].empty())
                mp2.erase(minFreq);
            // remove the key with min freq and min time from map1
            mp1.erase(delKey);
        }

        /* ------ INSERT ------ */

        // add a new entry with freq 1 and curr time in map2
        mp2[1][time] = key;
        // add a new entry 'key' with 'value', freq 1 and curr time in map1
        mp1[key] = {value, 1, time};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */