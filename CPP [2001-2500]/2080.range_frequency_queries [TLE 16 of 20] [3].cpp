class RangeFreqQuery {
private:
    vector<int> arr;
    unordered_map<int, vector<int>> mp; // num -> indexes

    int binarySearch1(vector<int> &arr, int key)
    {
        int l=0, r=arr.size()-1;
        int idx = r;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(arr[mid] >= key) // move to left subarray
            {
                r = mid - 1;
                idx = mid;
            }
            else // move to right subarray
                l = mid + 1;
        }
        return idx;
    }

    int binarySearch2(vector<int> &arr, int key)
    {
        int l=0, r=arr.size()-1;
        int idx = l;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(arr[mid] <= key) // move to right subarray
            {
                l = mid + 1;
                idx = mid;
            }
            else // move to left subarray
                r = mid - 1;
        }
        return idx;
    }

public:
    RangeFreqQuery(vector<int>& arr) {
        this->arr = arr;
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) { 
        if(mp.find(value) == mp.end()) // value not found in map
            return 0;
        vector<int> indexes = mp[value];
        if(right < indexes[0] || left > indexes[indexes.size()-1]) // given range is out of bounds
            return 0;
        return binarySearch2(indexes, right) - binarySearch1(indexes, left) + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */