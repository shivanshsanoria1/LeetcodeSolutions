class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int diff = 0;
        for(int i=0; i<k; i++)
            diff += nums[n-1-i] - nums[i];

        return diff;
    }
};