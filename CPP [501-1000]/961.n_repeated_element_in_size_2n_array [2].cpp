class Solution {
public:
    int repeatedNTimes(vector<int>& nums) { // T.C=O(n*logn), S.C.=O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0] == nums[n/2-1]) // 1st half
            return nums[0];
        else if(nums[n/2] == nums[n-1]) // 2nd half
            return nums[n-1];
        return nums[n/2]; // in both 1st and 2nd halves
    }
};
// when input array (of size 2n) is sorted, the required element forms a block of size n
// this block can either be in the 1st half, 2nd half or in both 1st and 2nd halves
// 1st half is from index [0 to n/2-1] and 2nd half is from index [n/2 to n-1]