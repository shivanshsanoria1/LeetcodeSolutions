class Solution {
public:
    // T.C.=O(n), S.C.=O(k)
    int subarraysDivByK(vector<int>& nums, int k) {
        // subarray sum % k -> freq
        unordered_map<int, int> mp;

        int prefixSum = 0;
        int count = 0;

        for(int num: nums)
        {
            prefixSum += num;
            // prefixMod is (prefixSum % k)
            int prefixMod = prefixSum;
            // in case where prefixSum is -ive, 
            // prefixMod must be made +ive before taking % with k
            if(prefixSum < 0)
                prefixMod += abs(prefixSum)/k * k + k;

            prefixMod %= k;

            if(prefixMod == 0)
                count++;
            
            count += mp[prefixMod];

            mp[prefixMod]++;
        }

        return count;
    }
};