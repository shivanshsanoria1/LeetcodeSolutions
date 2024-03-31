class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int count = 0;
        int left = 0, right = 0;
        // index of the latest occurence of minK and maxK respectively
        int minK_idx = -1, maxK_idx = -1;

        while(right < nums.size())
        {
            // nums[right] is a bad element which has made the
            // subarray in range [left, right] invalid
            // so now check in range [right + 1, ...]
            if(nums[right] < minK || nums[right] > maxK)
            {
                // update 'left'
                left = right + 1;
                // reset the minK and maxK indexes
                minK_idx = -1;
                maxK_idx = -1;
            }
            else
            {
                // update the minK and maxK indexes
                if(nums[right] == minK)
                    minK_idx = right;
                if(nums[right] == maxK)
                    maxK_idx = right;
                
                // all the subarrays in range [left, min(minK_idx, maxK_idx)]
                // are also valid
                if(minK_idx != -1 && maxK_idx != -1)
                    count += min(minK_idx, maxK_idx) - left + 1;
            }

            right++;
        }

        return count;
    }
};