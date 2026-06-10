class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) { // T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        long long int sum = 0;
        int maxWindowSize = 1;
        while(right < nums.size())
        {
            sum += nums[right];
            // decrease the size of window
            while((long long int)nums[right] * (right - left + 1) > sum + k)
            {
                sum -= nums[left];
                left++;
            }
            maxWindowSize = max(maxWindowSize, right - left + 1);
            right++;
        }
        return maxWindowSize;
    }
};