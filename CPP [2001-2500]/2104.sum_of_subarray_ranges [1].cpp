class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long int ans = 0;
        for(int i=0; i<n; i++)
        {
            int minVal = INT_MAX;
            int maxVal = INT_MIN;
            for(int j=i; j<n; j++)
            {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                ans += maxVal - minVal;
            }
        }
        return ans;
    }
};