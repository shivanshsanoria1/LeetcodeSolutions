class RangeFreqQuery {
private:
    vector<int> arr;

public:
    RangeFreqQuery(vector<int>& arr) {
        this->arr = arr;
    }
    
    int query(int left, int right, int value) { // T.C.=O(n)
        int freq = 0;
        for(int i=left; i<=right; i++)
            if(arr[i] == value)
                freq++;
        return freq;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */