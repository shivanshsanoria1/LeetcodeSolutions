class TimeMap {
private:
    typedef pair<string, int> PI;
    unordered_map<string, vector<PI>> mp; // key -> [{val1,t1}, {val2,t2}, {val3,t3}, ...]

public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto arr = mp[key];
        for(int i=arr.size()-1; i>=0; i--)
            if(arr[i].second <= timestamp) // time <= timestamp
                return arr[i].first; // value
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */