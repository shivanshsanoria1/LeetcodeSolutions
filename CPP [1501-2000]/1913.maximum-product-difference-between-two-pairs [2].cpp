class Solution {
public:
    // T.C.=O(nlogn), S.C.=O(1)
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        return nums[n-1]*nums[n-2] - nums[0]*nums[1];
    }
};