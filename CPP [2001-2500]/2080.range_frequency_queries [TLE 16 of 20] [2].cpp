class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> mp; // num -> indexes

public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) { // T.C.=O(n)
        int freq = 0;
        vector<int> indexes = mp[value];
        for(int idx: indexes)
            if(idx >= left && idx <= right)
                freq++;
        return freq;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */