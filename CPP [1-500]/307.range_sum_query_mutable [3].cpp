class FenwickTree{
private:
    vector<int> bit;

public:
    FenwickTree(){
        this->bit.clear();
    }

    FenwickTree(vector<int>& nums){
        int n=nums.size();
        this->bit.resize(n + 1, 0);

        for(int i=0; i<n; i++)
            update(i, nums[i]);
    }

    void update(int idx, int val){
        for(int i = idx + 1; i < bit.size(); i += i&(-i))
            bit[i] += val;
    }

    int prefixSum(int idx){
        int sum = 0;
        for(int i = idx + 1; i > 0; i -= i&(-i))
            sum += bit[i];

        return sum;
    }
};

class NumArray {
private:
    vector<int> nums;
    FenwickTree FT;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->FT = FenwickTree(nums);
    }
    
    void update(int index, int val) {
        FT.update(index, val - nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return FT.prefixSum(right) - FT.prefixSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */