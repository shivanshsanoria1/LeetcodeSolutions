class Solution {
public:
    int singleNumber(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        int n=nums.size();
        if(n == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        for(int i=1; i<n-1; i++)
            if(nums[i-1] != nums[i] && nums[i] != nums[i+1])
                return nums[i];
        // check for 0th and last indexes
        return nums[0] != nums[1] ? nums[0] : nums[n-1];
    }
};