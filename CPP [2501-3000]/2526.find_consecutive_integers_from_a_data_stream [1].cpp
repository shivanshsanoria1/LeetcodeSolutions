class DataStream {
private:
    int value = 0;
    int k = 0;

    queue<int> q;

    // num -> freq
    unordered_map<int, int> mp;

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        while(!this->q.empty())
            this->q.pop();
        this->mp.clear();
    }
    
    // T.C.=O(1), S.C.=O(k)
    bool consec(int num) {
        q.push(num);
        mp[num]++;

        if(q.size() < k)
            return false;
        
        if(q.size() == k + 1)
        {
            int val = q.front();
            q.pop();

            mp[val]--;
            if(mp[val] == 0)
                mp.erase(val);
        }

        return mp.size() == 1 && mp.begin()->first == value;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */