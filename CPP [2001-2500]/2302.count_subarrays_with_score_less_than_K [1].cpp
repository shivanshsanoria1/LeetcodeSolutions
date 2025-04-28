class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // sliding-window
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int left = 0, right = 0;
        long long int sum = 0;
        long long int count = 0;

        while(right < n)
        {
            // expand the window by 1
            sum += nums[right];
            
            // keep on shrinking the window until it becomes valid
            while(sum * (right - left + 1) >= k)
            {
                sum -= nums[left];
                left++;
            }

            // every subarray formed from the 
            // curr valid window is also valid
            count += right - left + 1;
            
            right++;
        }

        return count;
    }
};