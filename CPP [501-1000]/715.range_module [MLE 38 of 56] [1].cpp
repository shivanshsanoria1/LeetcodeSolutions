class RangeModule {
private:
    unordered_set<int> nums;

public:
    RangeModule() {
        this->nums.clear();
    }
    
    // T.C.=O(right - left), S.C.=O(right - left)
    void addRange(int left, int right) {
        for(int i=left; i<right; i++)
            this->nums.insert(i);
    }
    
    // T.C.=O(right - left), S.C.=O(1)
    bool queryRange(int left, int right) {
        for(int i=left; i<right; i++)
            // 'i' not found in set
            if(this->nums.find(i) == this->nums.end())
                return false;
        return true;
    }
    
    // T.C.=O(right - left), S.C.=O(1)
    void removeRange(int left, int right) {
        for(int i=left; i<right; i++)
            this->nums.erase(i);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */