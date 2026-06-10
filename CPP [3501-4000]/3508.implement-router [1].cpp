class Router {
private:
    // max-size of queue
    int limit = 0;
    // {source, destination, timestamp}
    queue<vector<int>> q;
    // {source + destination + timestamp}
    unordered_set<string> s;
    // destination -> {start idx, {timestamp}}
    unordered_map<int, pair<int, vector<int>>> mp;

    string getHash(int source, int destination, int timestamp){
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

    // returns the leftmost-index of the element >= key
    // nums[] starts at the index startIdx
    int binarySearch1(vector<int>& nums, int startIdx, int key){
        int left = startIdx, right = nums.size()-1;
        int idx = -1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] >= key)
            {
                idx = mid;
                right = mid - 1;
            }
            else // nums[mid] < key
                left = mid + 1;
        }

        return idx;
    }

    // returns the rightmost-index of the element <= key
    // nums[] starts at the index startIdx
    int binarySearch2(vector<int>& nums, int startIdx, int key){
        int left = startIdx, right = nums.size()-1;
        int idx = -1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] <= key)
            {
                idx = mid;
                left = mid + 1;
            }
            else // nums[mid] > key
                right = mid - 1;
        }

        return idx;
    }

public:
    Router(int memoryLimit) {
        this->limit = memoryLimit;
        this->s.clear();
        this->mp.clear();
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string hash = getHash(source, destination, timestamp);
        // same packet already in queue
        if(s.find(hash) != s.end())
            return false;

        // queue is full, remove the oldest packet
        if(q.size() == limit)
            forwardPacket();

        q.push({source, destination, timestamp});
        s.insert(hash);

        // dest node not found in map
        if(mp.find(destination) == mp.end())
            mp[destination] = {0, {}};
        // add the timestamp of curr node
        mp[destination].second.push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty())
            return {};

        vector<int> packet = q.front();
        q.pop();
        s.erase(getHash(packet[0], packet[1], packet[2]));
        // increment the start index to account for the removed packet
        mp[packet[1]].first++;

        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        // dest node not found
        if(mp.find(destination) == mp.end())
            return 0;

        int startIdx = mp[destination].first;
        vector<int>& times = mp[destination].second;

        // no packets with the curr dest node in queue
        if(startIdx >= times.size())
            return 0;
        
        int i = binarySearch1(times, startIdx, startTime);
        // no nodes with time >= startTime
        if(i == -1)
            return 0;

        int j = binarySearch2(times, startIdx, endTime);
        // no nodes with time <= endTime
        if(j == -1)
            return 0;

        return j-i+1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */