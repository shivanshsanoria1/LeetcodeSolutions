class TimeMap {
private:
    // key -> [{t1,val1}, {t2,val2}, {t3,val3}, ...]
    unordered_map<string, vector<pair<int, string>>> mp; 

public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) // key not found in map
            return "";
        auto& arr = mp[key];
        int left = 0, right = arr.size()-1;
        string ans = "";
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(arr[mid].first <= timestamp)
            {
                ans = arr[mid].second;
                left = mid + 1; // move to the right subarray
            }
            else // move to the left subarray
                right = mid - 1;
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