class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++)
            prefixSum[i] += prefixSum[i-1] + nums[i];

        int sum = 0;
        for(int i=0; i<n; i++)
        {
            int start = max(0, i - nums[i]);
            sum += start - 1 >= 0 ? prefixSum[i] - prefixSum[start - 1] : prefixSum[i];
        }
        
        return sum;
    }
};