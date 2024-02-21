class TimeMap {
private:
    // key -> map(timestamp -> value)
    unordered_map<string, unordered_map<int, string>> mp;

public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key) == 0) // key not present in mp
            return "";
        for(int t=timestamp; t>=1; t--)
            if(mp[key].count(t) > 0) // t present in mp[key]
                return mp[key][t];
        return ""; // no value found with time <= timestamp for the given key
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */