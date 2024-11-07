class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    // similar to Bubble-sort
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n-1; i++)
            for(int j=0; j<n-1-i; j++)
            {
                if(nums[j] <= nums[j+1])
                    continue;
                else if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1]))
                    swap(nums[j], nums[j+1]);
                else
                    return false;
            }

        return true;
    }
};