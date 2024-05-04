class NumArray {
private:
    vector<int> nums;
    vector<int> prefixSum;
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();

        prefixSum.resize(n);

        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];
    }
    
    // T.C.=O(n)
    void update(int index, int val) { 
        // difference between new value and old value
        int diff = val - nums[index]; 
        // update the value in the original array
        nums[index] = val; 
        // update the prefix sum for indicies 'index' to 'n-1'
        for(int i=index; i<nums.size(); i++) 
            prefixSum[i] += diff;
    }
    
    // T.C.=O(1)
    int sumRange(int left, int right) { 
        return left == 0 ? prefixSum[right] : prefixSum[right] - prefixSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */