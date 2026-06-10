class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int n=nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int preSum = 0;
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++)
        {
            preSum += nums[i];
            ans[i] += (totalSum - preSum) - nums[i] * (n-i-1);
            ans[i] += nums[i] * i - (preSum - nums[i]);
        }
        return ans;
    }
};