class Solution {
private:
    // returns num of subarrays with sum <= k
    int subarraySumLessThanOrEqualTo_K(vector<int>& nums, int k){
        int left = 0, right = 0;
        int prefixSum = 0;
        int count = 0;

        while(right < nums.size())
        {
            // expand the window-size by 1
            prefixSum += nums[right];

            // keep on shrinking the window until 
            // it becomes valid, ie, its sum <= k
            while(prefixSum > k)
            {
                prefixSum -= nums[left];
                left++;
            }

            // since the window is now valid, ie, its sum <= k, 
            // every subarray starting at 'left' and 
            // ending at any index in range [left, right] is also valid, 
            // ie, num of valid subarrays = window size
            count += right - left + 1;
            
            right++;
        }

        return count;
    }

public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-Window
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal == 0)
            return subarraySumLessThanOrEqualTo_K(nums, goal);

        return subarraySumLessThanOrEqualTo_K(nums, goal) - subarraySumLessThanOrEqualTo_K(nums, goal - 1);
    }
};
/*
# similar: [1248. count-number-of-nice-subarrays]
# window is valid if its sum <= k
# window is invalid if its sum > k
*/