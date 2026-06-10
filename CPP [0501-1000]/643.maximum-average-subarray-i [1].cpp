class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) { // T.C.=O(n), S.C.=O(1)
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<k; i++) // sum of subarray starting at index 0
            sum += nums[i];
        int maxSum = sum;
        int start = 1, end = k;
        while(end < n)
        {
            // include nums[end] and remove nums[start-1] from the curr sum
            sum += nums[end] - nums[start - 1];
            maxSum = max(maxSum, sum);
            start++;
            end++;
        }
        return (double)maxSum/k;
    }
};