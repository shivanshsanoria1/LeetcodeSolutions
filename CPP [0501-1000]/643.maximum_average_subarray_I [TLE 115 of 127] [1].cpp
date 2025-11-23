class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int i=0; i<n-k+1; i++)
        {
            int sum = 0;
            for(int j=i; j<i+k; j++)
                sum += nums[j];
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum/k;
    }
};