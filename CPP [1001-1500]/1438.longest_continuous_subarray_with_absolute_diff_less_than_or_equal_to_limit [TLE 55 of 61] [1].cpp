class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            int maxVal = 0;
            int minVal = INT_MAX;

            for(int j=i; j<n; j++)
            {
                maxVal = max(maxVal, nums[j]);
                minVal = min(minVal, nums[j]);

                if(maxVal - minVal <= limit)
                    ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};