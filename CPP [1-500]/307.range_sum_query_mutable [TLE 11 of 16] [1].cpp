class NumArray {
// S.C.=O(1)
private:
    vector<int> nums;
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
    }
    
    void update(int index, int val) { // T.C.=O(1)
        nums[index] = val;
    }
    
    int sumRange(int left, int right) { // T.C.=O(n)
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