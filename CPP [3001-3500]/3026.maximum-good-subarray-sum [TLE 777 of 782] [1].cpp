class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long int maxSum = INT_MIN;
        int n=nums.size();
        for(int i=0; i<n-1; i++)
        {
            long long int sum = nums[i];
            for(int j=i+1; j<n; j++)
            {
                sum += nums[j];
                if(abs(nums[i] - nums[j]) == k)
                    maxSum = max(maxSum, sum);
            }
        }
        return maxSum == INT_MIN ? 0 : maxSum;
    }
};