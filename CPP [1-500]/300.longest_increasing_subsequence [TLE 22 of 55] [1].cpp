class Solution {
private:
    int lis(vector<int>& nums, int parVal, int i){
        if(i >= nums.size())
            return 0;
        int include = nums[i] > parVal ? 1 + lis(nums, nums[i], i+1) : 0;
        int exclude = lis(nums, parVal, i+1);
        return max(include, exclude);
    }

public:
    // T.C.=O(2^n), Recursion
    int lengthOfLIS(vector<int>& nums) { 
        return lis(nums, INT_MIN, 0);
    }
};