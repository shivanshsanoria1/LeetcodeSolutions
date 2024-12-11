class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    // Sorting + Sliding-window
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0, right = 0;
        int ans = 0;
        while(right < nums.size())
        {
            if(nums[right] - nums[left] <= 2*k)
                ans = max(ans, right - left + 1);
            else
                left++;
            
            right++;
        }

        return ans;
    }
};