class MajorityChecker {
private:
    vector<int> nums;

public:
    MajorityChecker(vector<int>& arr) {
        this->nums = arr;
    }
    
    // T.C.=O(n)
    int query(int left, int right, int threshold) {
        // num -> freq
        unordered_map<int, int> mp; 
        for(int i=left; i<=right; i++)
        {
            mp[nums[i]]++;

            if(mp[nums[i]] == threshold)
                return nums[i];
        }

        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */