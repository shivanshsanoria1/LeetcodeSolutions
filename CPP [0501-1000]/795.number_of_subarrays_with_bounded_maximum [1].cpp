class Solution {
private:
    // returns the number of subarrays with max-element <= K
    int subarrayCountWithMaxElementLessThanEqual_K(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = 0;

        while(right < nums.size())
        {
            // nums[right] is the bad-element that has broken our streak,
            // any subarray with nums[right] is invalid, so we skip this
            // element by moving the left-pointer 1-place to the right of
            // this element
            if(nums[right] > k)
                left = right + 1;
            // increment count by the window size
            else
                count += right - left + 1;

            right++;
        }

        return count;
    }

public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int count1 = subarrayCountWithMaxElementLessThanEqual_K(nums, right);
        int count2 = subarrayCountWithMaxElementLessThanEqual_K(nums, left - 1); 

        return count1 - count2;
    }
};
/*
# { num of subarrays with max-element in range [left, right] } = 
  { num of subarrays with max-element in range [minElement, right] } - 
  { num of subarrays with max-element in range [minElement, left) }
*/