class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int numberOfSubarrays(vector<int>& nums, int k) {
        // prefix-sum -> freq
        unordered_map<int, int> mp;

        int prefixSum = 0;
        int count = 0;

        for(int num: nums)
        {
            prefixSum += num % 2;

            if(prefixSum == k)
                count++;

            count += mp[prefixSum - k];
            
            mp[prefixSum]++;
        }

        return count;
    }
};
/*
# prerequisite: [930. binary subarrays with sum]
# imagine replacing each odd num with 1 and even num with 0
*/