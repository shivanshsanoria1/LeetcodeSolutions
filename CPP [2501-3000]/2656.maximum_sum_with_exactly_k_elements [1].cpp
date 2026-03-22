class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        return maxVal * k + ((k-1)*k)/2;
    }
};
/*
ans = (maxVal + 0) + (maxVal + 1) + (maxVal + 2) + ... + (maxVal + k-1)
    = maxVal * k + ((k-1) * k) / 2
*/