class Solution {
private:
    // returns num of subarrays with sum <= k
    int subarraySumLessThanOrEqualTo_K(vector<int>& nums, int k){
        int sum = 0;
        int left = 0, right = 0;
        int count = 0;

        while(right < nums.size())
        {
            sum += nums[right];

            while(sum > k)
            {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
            
            right++;
        }

        return count;
    }

public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal == 0)
            return subarraySumLessThanOrEqualTo_K(nums, goal);

        return subarraySumLessThanOrEqualTo_K(nums, goal) - subarraySumLessThanOrEqualTo_K(nums, goal - 1);
    }
};