class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    // num -> freq
    unordered_map<int, int> mp2;

public:
    // T.C.=O(n1 + n2)
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1.clear();
        this->nums2.clear();
        this->mp2.clear();

        for(int num: nums1)
            this->nums1.push_back(num);
        
        for(int num: nums2)
            this->nums2.push_back(num);
        
        for(int num: nums2)
            this->mp2[num]++;
    }
    
    // T.C.=O(1)
    void add(int index, int val) {
        int oldVal = nums2[index];

        mp2[oldVal]--;
        if(mp2[oldVal] == 0)
            mp2.erase(oldVal);
        
        nums2[index] += val;

        mp2[nums2[index]]++;
    }
    
    // T.C.=O(n1)
    int count(int tot) {
        int count = 0;

        for(int num: nums1)
            count += mp2[tot - num];
        
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */