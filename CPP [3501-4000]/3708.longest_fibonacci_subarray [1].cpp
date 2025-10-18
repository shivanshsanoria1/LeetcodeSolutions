class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Sliding-window
    int longestSubarray(vector<int>& nums) {
        // array of length 2 is considered Fibonacci here
        int ans = 2;
        for(int left = 0, right = 2; right < nums.size(); right++){
            // curr subarray is Fibonacci
            if(nums[right - 2] + nums[right - 1] == nums[right])
                ans = max(ans, right - left + 1);
            // 'right' has broken out Fibonacci streak, 
            // so reset 'left' to find another Fibonacci subarray
            else
                left = right - 1;
        }

        return ans;
    }
};