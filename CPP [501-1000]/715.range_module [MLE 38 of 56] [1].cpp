class RangeModule {
private:
    unordered_set<int> nums;

public:
    RangeModule() {
        this->nums.clear();
    }
    
    // T.C.=O(right - left)
    void addRange(int left, int right) {
        for(int i=left; i<right; i++)
            nums.insert(i);
    }
    
    // T.C.=O(right - left)
    bool queryRange(int left, int right) {
        for(int i=left; i<right; i++)
            // 'i' not found in set
            if(nums.find(i) == nums.end())
                return false;
        return true;
    }
    
    // T.C.=O(right - left)
    void removeRange(int left, int right) {
        for(int i=left; i<right; i++)
            nums.erase(i);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */