class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window / 2-pointer
    int longestMonotonicSubarray(vector<int>& nums) {
        int left = 0, right = 1;
        // max length of strictly-increasing subarray
        int maxLenInc = 1;

        while(right < nums.size())
        {
            // element at 'right' is the bad element which has 
            // broken our streak so start the new streak from 'right'
            if(nums[right - 1] >= nums[right])
                left = right;
            // curr window is valid so calculate the max
            // with the curr window size
            else
                maxLenInc = max(maxLenInc, right - left + 1);

            right++;
        }

        left = 0, right = 1;
        // max length of strictly-decreasing subarray
        int maxLenDec = 1;

        while(right < nums.size())
        {
            // element at 'right' is the bad element which has 
            // broken our streak so start the new streak from 'right'
            if(nums[right - 1] <= nums[right])
                left = right;
            // curr window is valid so calculate the max
            // with the curr window size
            else
                maxLenInc = max(maxLenInc, right - left + 1);

            right++;
        }

        return max(maxLenInc, maxLenDec);
    }
};