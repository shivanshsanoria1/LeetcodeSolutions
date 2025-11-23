class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    int findKthLargest(vector<int>& nums, int k) { 
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};