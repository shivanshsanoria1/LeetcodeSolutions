class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        int diff = maxNum - minNum;
        return diff <= 2*k ? 0 : diff - 2*k;
    }
};