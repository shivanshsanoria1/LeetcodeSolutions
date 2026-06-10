class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Sliding-window
    int maxSubarrayLength(vector<int>& nums, int k) {
        // num -> freq
        unordered_map<int, int> mp;
        
        int maxLen = 0;
        int left = 0, right = 0;

        while(right < nums.size())
        {
            // expand the window
            mp[nums[right]]++;

            // shrink the window until it becomes valid
            while(mp[nums[right]] > k)
            {
                mp[nums[left]]--;
                left++;
            }

            // check the window size
            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};