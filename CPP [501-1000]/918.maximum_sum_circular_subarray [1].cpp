class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) { // T.C.=O(n), S.C.=O(1)
        int n=nums.size();
        int maxSum = nums[0];
        int minSum = nums[0];
        int currMaxSum = nums[0];
        int currMinSum = nums[0];
        int totalSum = nums[0];
        for(int i=1; i<n; i++)
        {
            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum, currMaxSum);

            currMinSum = min(currMinSum + nums[i], nums[i]);
            minSum = min(minSum, currMinSum);

            totalSum += nums[i];
        }
        return (totalSum - minSum == 0) ? maxSum : max(maxSum, totalSum - minSum);
    }
};
/*
# Similar to Kadane's algo.
# maxSum is the max subarray sum when this subarray is continous
# minSum is the min subarray sum when this subarray is continous
# (totalSum - minSum) gives the max subarray sum when the required subarray is discontinous
# (totalSum - minSum == 0) means all nums in array are -ive, so just return maxSum,
ie, least -ive num in array
*/