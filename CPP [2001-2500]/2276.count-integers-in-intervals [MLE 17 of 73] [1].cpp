class CountIntervals {
private:
    unordered_set<int> nums;

public:
    CountIntervals() {
        this->nums.clear();
    }
    
    // T.C.=O(right - left)
    void add(int left, int right) {
        for(int i=left; i<=right; i++)
            nums.insert(i);
    }
    
    // T.C.=O(1)
    int count() {
        return nums.size();
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */