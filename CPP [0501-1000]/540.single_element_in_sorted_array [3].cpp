class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int n = nums.size();
        if(n == 1) // array length is 1
            return nums[0];
        if(nums[0] != nums[1]) // element is at the start of the array
            return nums[0];
        if(nums[n-2] != nums[n-1]) // element is at the end of the array
            return nums[n-1];
        for(int i=1; i<n-1; i++)
            if(nums[i-1] != nums[i] && nums[i] != nums[i+1])
                return nums[i];
        return -1;
    }
};
// array is always of odd length