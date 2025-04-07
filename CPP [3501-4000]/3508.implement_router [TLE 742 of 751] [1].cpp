class Router {
private:
    // max-size of queue
    int limit = 0;
    // {source, destination, timestamp}
    queue<vector<int>> q;
    // {source + destination + timestamp}
    unordered_set<string> s;

    string getHash(int source, int destination, int timestamp){
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        this->limit = memoryLimit;
        this->s.clear();
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

        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty())
            return {};

        vector<int> packet = q.front();
        q.pop();
        s.erase(getHash(packet[0], packet[1], packet[2]));

        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int sz = q.size();
        int count = 0;
        // remove all the packets from the front 
        // and add them back at the rear of queue
        while(sz--)
        {
            vector<int> packet = q.front();
            q.pop();
            q.push(packet);

            if(packet[1] == destination && startTime <= packet[2] && packet[2] <= endTime)
                count++;
        }

        return count;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */