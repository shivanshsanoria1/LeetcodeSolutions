class MajorityChecker {
private:
    vector<int> nums;

public:
    MajorityChecker(vector<int>& arr) {
        for(int num: arr)
            nums.push_back(num);
    }
    
    int query(int left, int right, int threshold) {
        unordered_map<int, int> mp; // num -> freq
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