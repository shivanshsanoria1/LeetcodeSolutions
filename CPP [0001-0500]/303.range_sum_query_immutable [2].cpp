class NumArray {
private:
    vector<int> cum_sum; //cumulative sum

public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        cum_sum.resize(n,0);
        cum_sum[0]= nums[0];
        for(int i=1; i<n; i++)
            cum_sum[i]= cum_sum[i-1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return (left==0) ? cum_sum[right] : cum_sum[right]-cum_sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */