class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int maxSum = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int currSum = nums[i];
            maxSum = max(maxSum, currSum);
            for(int j=(i+1)%n; j != (i < n ? i : 0); j=(j+1)%n)
            {
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};