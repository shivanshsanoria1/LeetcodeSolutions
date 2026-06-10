class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long int> preSum(n);
        preSum[0] = nums[0];
        for(int i=1; i<n; i++)
            preSum[i] = nums[i] + preSum[i-1];

        unordered_map<int, vector<int>> mp; // num -> {index}
        for(int i=0; i<n; i++)
            mp[nums[i]].push_back(i);
        
        long long int maxSum = LLONG_MIN;
        for(int i=0; i<n; i++)
        {
            // (nums[i] + k) not found in map
            if(mp.find(nums[i] + k) == mp.end())
                continue;
            for(int j: mp[nums[i] + k])
            {
                int startIdx = min(i, j);
                int endIdx = max(i, j);
                long long int currSum = startIdx == 0 ? preSum[endIdx] : preSum[endIdx] - preSum[startIdx - 1];
                maxSum = max(maxSum, currSum);
            }
        }

        return maxSum == LLONG_MIN ? 0 : maxSum;
    }
};