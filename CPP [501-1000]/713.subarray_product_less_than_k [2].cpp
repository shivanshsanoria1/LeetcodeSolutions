class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-Window
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // since min value of nums[i] is 1 so min possible product is 1
        if(k <= 1)
            return 0;

        int left = 0, right = 0;
        int pro = 1;
        int count = 0;

        while(right < nums.size())
        {
            // expand the window
            pro *= nums[right];

            // reduce the window till the product becomes < k
            while(pro >= k)
            {
                pro /= nums[left];
                left++;
            }

            // increment count by the size of window
            count += right - left + 1;

            right++;
        }

        return count;
    }
};
