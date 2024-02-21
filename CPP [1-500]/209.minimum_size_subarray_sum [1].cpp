class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) { // sliding-window, T.C.=O(n), S.C.=O(1)
        int left = 0, right = 0;
        int sum = 0; 
        int minLen = INT_MAX; // min length of valid subarray (subarray whose sum >= target)
        while(right < nums.size())
        {
            sum += nums[right];
            if(sum >= target) // valid subarray found
                minLen = min(minLen, right - left + 1);
            while(sum >= target) // while the subarray is valid increment the left
            {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++; 
            }
            right++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};