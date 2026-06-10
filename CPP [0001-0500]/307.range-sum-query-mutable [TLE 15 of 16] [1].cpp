class NumArray {
private:
    vector<int> nums;
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    // T.C.=O(1)
    void update(int index, int val) { 
        nums[index] = val;
    }
    
    // T.C.=O(n)
    int sumRange(int left, int right) { 
        int sum = 0;
        for(int i=left; i<=right; i++)
            sum += nums[i];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */