class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) { // Greedy, T.C.=O(n), S.C.=O(1)
        for(int i=1; i<nums.size()-1; i++)
            if(min(nums[i-1], nums[i+1]) < nums[i] && max(nums[i-1], nums[i+1]) > nums[i])
                swap(nums[i], nums[i+1]);
        return nums;
    }
};
/*
# nums[i] can be the avg of nums[i-1] and nums[i+1] if 
  one of them is smaller and the other is larger than nums[i]
# nums[i] can never be the avg of nums[i-1] and nums[i+1] if 
  both nums[i-1] and nums[i+1] are smaller or larger than nums[i]
*/