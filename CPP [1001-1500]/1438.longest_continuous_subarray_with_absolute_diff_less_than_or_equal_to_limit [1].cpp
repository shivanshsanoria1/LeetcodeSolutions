class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    // Sliding-window
    int longestSubarray(vector<int>& nums, int limit) {
        // num -> freq
        map<int, int> mp;

        int left = 0, right = 0;
        int ans = 0;

        while(right < nums.size())
        {
            // expand the window size by 1
            mp[nums[right]]++;

            // keep on shrinking the window size until it becomes valid
            while(mp.rbegin()->first - mp.begin()->first > limit)
            {
                if(--mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                
                left++;
            }

            ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};
// window is considered valid if maxNum - minNum <= limit
// window is considered invalid if maxNum - minNum > limit