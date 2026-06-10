class Solution {
private:
    int lis(vector<int>& nums, int i, int prevIdx){
        if(i >= nums.size())
            return 0;

        int exclude = lis(nums, i+1, prevIdx);
        int include = prevIdx == -1 || nums[i] > nums[prevIdx] ? 1 + lis(nums, i+1, i) : 0;

        return max(exclude, include);
    }

public:
    // T.C.=O(2^n)
    // Recursion
    int lengthOfLIS(vector<int>& nums) { 
        return lis(nums, 0, -1);
    }
};