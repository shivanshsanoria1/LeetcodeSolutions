class RangeFreqQuery {
private:
    // num -> {index}
    unordered_map<int, vector<int>> mp; 

public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]].push_back(i);
    }
    
    // T.C.=O(n)
    int query(int left, int right, int value) {
        // value not found in map
        if(mp.find(value) == mp.end()) 
            return 0;

        vector<int>& indexes = mp[value];

        // range [left, right] does not overlap with indexes[]
        if(right < indexes[0] || indexes.back() < left)
            return 0;

        // first index in indexes[] >= left
        int firstIdx = -1;
        for(int i=0; i<indexes.size(); i++)
            if(indexes[i] >= left)
            {
                firstIdx = i;
                break;
            }

        // last index in indexes[] <= right
        int lastIdx = -1;
        for(int i=indexes.size()-1; i>=0; i--)
            if(indexes[i] <= right)
            {
                lastIdx = i;
                break;
            }

        return lastIdx - firstIdx + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */