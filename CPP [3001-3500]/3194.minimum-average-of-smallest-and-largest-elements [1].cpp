class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    // 2-pointer
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size()-1;
        int minPairSum = INT_MAX;

        while(left <= right)
        {
            minPairSum = min(minPairSum, nums[left] + nums[right]);

            left++;
            right--;
        }

        return (double)minPairSum / 2;
    }
};