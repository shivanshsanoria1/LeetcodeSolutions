class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // array must have atleast k elements
        if(n < k)
            return 0;

        int maxNum = *max_element(nums.begin(), nums.end());
        int maxNumCount = count(nums.begin(), nums.end(), maxNum);
        // max-num appears less than k times in nums[]
        if(maxNumCount < k)
            return 0;

        long long int count = 0;
        maxNumCount = 0;
        int left = 0, right = 0;

        while(right < n)
        {
            // expand the window by 1
            if(nums[right] == maxNum)
                maxNumCount++;

            // keep on shrinking the window until it becomes valid
            while(maxNumCount == k)
            {
                if(nums[left] == maxNum)
                    maxNumCount--;
                left++;
            }

            // every subarray starting at index 'left' 
            // of curr window is also valid
            count += right - left + 1;

            right++;
        }

        return ((long long int)n*(n+1))/2 - count;
    }
};

/*
# imagine the replacing the original array with a binary array
  where the max element is replaced by 1 and all other elements
  are replaced by 0
# { num of subarrays with >= to K 1's } = 
  { total num of subarrays } - { num of subarrays with <  K 1's }
*/