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
        string ans = "";
        int maxTime = 0; // max time smaller or equal to timestamp
        auto mp2 = mp[key];
        for(auto it: mp2)
        {
            int time = it.first;
            string value = it.second;
            if(time <= timestamp && time >= maxTime)
            {
                maxTime = time; // update max time with curr time
                ans = value; // update the ans with curr value
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */