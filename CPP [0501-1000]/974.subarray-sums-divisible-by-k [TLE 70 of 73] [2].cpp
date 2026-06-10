class Solution {
public:
    // T.C.=O(), S.C.=O(n)
    int subarraysDivByK(vector<int>& nums, int k) {
        // prefix sum -> freq
        unordered_map<int, int> mp;

        int minSum = INT_MAX, maxSum = INT_MIN;
        int count = 0;
        int sum = 0;

        for(int num: nums)
        {
            sum += num;

            minSum = min(minSum, sum);
            maxSum = max(maxSum, sum);

            if(sum % k == 0)
                count++;

            count += mp[sum];

            int mul = 1;
            while(sum + mul*k <= maxSum)
            {
                count += mp[sum + mul*k];
                mul++;
            }

            mul = 1;
            while(sum - mul*k >= minSum)
            {
                count += mp[sum - mul*k];
                mul++;
            }

            mp[sum]++;
        }

        return count;
    }
};