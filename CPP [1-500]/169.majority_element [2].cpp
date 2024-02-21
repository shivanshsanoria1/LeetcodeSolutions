class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    int majorityElement(vector<int>& nums) { 
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
/*
Example (when array is sorted)
# for odd length array, let n = 5, majority element min freq = 5/2 + 1 = 3
  indexes = 0 1 2 3 4
  majority element can be in index range [0,2], [1,3], [2,5]
  common index = 2, ie, n/2
# for even length array, let n = 6, majority element min freq = 6/2 + 1 = 4
  indexes = 0 1 2 3 4 5
  majority element can be in index range [0,3], [1,4], [2,5]
  common index = 3, ie, n/2
*/