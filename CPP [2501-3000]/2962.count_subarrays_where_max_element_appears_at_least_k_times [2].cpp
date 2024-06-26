class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        // array must have atleast k elements
        if(n < k)
            return 0;

        int maxNum = *max_element(nums.begin(), nums.end());
        long long int count = 0;
        int maxNumCount = 0;
        int left = 0, right = 0;

        while(right < n)
        {
            // expand the window
            if(nums[right] == maxNum)
                maxNumCount++;

            // shrink the window until it becomes valid
            while(maxNumCount == k)
            {
                if(nums[left] == maxNum)
                    maxNumCount--;
                left++;
            }

            // update the count
            count += left;

            right++;
        }

        return count;
    }
};
/*
# imagine the replacing the original array with a binary array
  where the max element is replaced by 1 and all other elements
  are replaced by 0
*/