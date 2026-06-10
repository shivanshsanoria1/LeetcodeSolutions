class RangeFreqQuery {
private:
    // num -> {index}
    unordered_map<int, vector<int>> mp; 

    // returns the index of first element >= key
    int binarySearch1(vector<int>& arr, int key){
        int left = 0, right = arr.size()-1;
        int idx = -1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(arr[mid] >= key)
            {
                idx = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return idx;
    }
    
    // returns the index of last element <= key
    int binarySearch2(vector<int>& arr, int key){
        int left = 0, right = arr.size()-1;
        int idx = -1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(arr[mid] <= key)
            {
                idx = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }

        return idx;
    }

public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++)
            mp[arr[i]].push_back(i);
    }
    
    // T.C.=O(logn)
    int query(int left, int right, int value) {
        // value not found in map
        if(mp.find(value) == mp.end()) 
            return 0;

        vector<int>& indexes = mp[value];

        // range [left, right] does not overlap with indexes[]
        if(right < indexes[0] || indexes.back() < left)
            return 0;

        // first index in indexes[] >= left
        int firstIdx = binarySearch1(indexes, left);
        // last index in indexes[] <= right
        int lastIdx = binarySearch2(indexes, right);

        return lastIdx - firstIdx + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */