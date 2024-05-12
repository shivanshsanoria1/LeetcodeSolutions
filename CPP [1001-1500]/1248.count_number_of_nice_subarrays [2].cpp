class Solution {
private:
    // returns num of subarrays with sum <= k
    int subarraySumLessThanOrEqualTo_K(vector<int>& nums, int k){
        int sum = 0;
        int left = 0, right = 0;
        int count = 0;

        while(right < nums.size())
        {
            sum += nums[right] % 2;

            while(sum > k)
            {
                sum -= nums[left] % 2;
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarraySumLessThanOrEqualTo_K(nums, k) - subarraySumLessThanOrEqualTo_K(nums, k-1);
    }
};
/*
# prerequisite: 930. "binary subarrays with sum"
# imagine replacing each odd num with 1 and even num with 0
*/