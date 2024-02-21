class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { // T.C.=O(nlogn)
        int n=nums.size();
        sort(nums.begin(), nums.end());
        return nums[n-k];
    }
};