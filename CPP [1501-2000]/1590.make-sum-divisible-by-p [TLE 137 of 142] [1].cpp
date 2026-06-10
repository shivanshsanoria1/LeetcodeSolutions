class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int minSubarray(vector<int>& nums, int p) {
        long long int totalSum = 0;
        for(int num: nums)
            totalSum += num;

        // total array sum is already divisible by p, 
        // so no need to remove any subarray
        if(totalSum % p == 0)
            return 0;

        int n=nums.size();
        int minLen = n;
        
        for(int i=0; i<n; i++)
        {
            long long int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];

                if((totalSum - sum) % p == 0)
                    minLen = min(minLen, j-i+1);
            }
        }

        return minLen == n ? -1 : minLen;
    }
};