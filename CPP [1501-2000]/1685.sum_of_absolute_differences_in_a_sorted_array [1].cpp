class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        int n=nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++)
            prefixSum[i] = nums[i] + prefixSum[i-1];
        
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++)
        {
            int preSum = i-1 >= 0 ? prefixSum[i-1] : 0;
            int postSum = prefixSum[n-1] - prefixSum[i];
            ans[i] += postSum - nums[i] * (n-i-1);
            ans[i] += i-1 >= 0 ? nums[i] * i - preSum : 0;
        }
        return ans;
    }
};