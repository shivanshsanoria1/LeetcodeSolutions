class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int waysToSplitArray(vector<int>& nums) {
        long long int totalSum = 0;
        for(int num: nums)
            totalSum += num;

        long long int prefixSum = 0;
        int count = 0;
        for(int i=0; i<nums.size()-1; i++)
        {
            prefixSum += nums[i];
            if(prefixSum >= totalSum - prefixSum)
                count++;
        }

        return count;
    }
};