class NumArray {
// S.C.=O(n)
private:
    vector<int> preSum; // prefix sum
    vector<int> nums;
    int n; // size of input array
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        preSum.resize(n);
        preSum[0] = nums[0];
        for(int i=1; i<n; i++)
            preSum[i] = preSum[i-1] + nums[i];
    }
    
    void update(int index, int val) { // T.C.=O(n)
        int diff = val - nums[index]; // difference between new value and old value
        nums[index] = val; // update the value in the original array
        for(int i=index; i<n; i++) // update the prefix sum for indicies 'index' to 'n-1'
            preSum[i] += diff;
    }
    
    int sumRange(int left, int right) { // T.C.=O(1)
        return left == 0 ? preSum[right] : preSum[right] - preSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */