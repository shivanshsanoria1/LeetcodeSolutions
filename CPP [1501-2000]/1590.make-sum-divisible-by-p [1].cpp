class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int minSubarray(vector<int>& nums, int p) {
        int totalSumMod = 0;
        for(int num: nums)
            totalSumMod = (totalSumMod + num) % p;
        
        // total array sum is already divisible by p, 
        // so no need to remove any subarray
        if(totalSumMod == 0)
            return 0;
        
        int n=nums.size();
        int currSumMod = 0;
        int minLen = n;
        // prefix-sum % p -> rightmost index 
        unordered_map<int, int> mp;
        // to handle the case where the 
        // subarray [0, i] needs to be removed
        mp[0] = -1;
        
        for(int i=0; i<n; i++)
        {
            currSumMod = (currSumMod + nums[i]) % p;

            int prevSumMod = (currSumMod - totalSumMod + p) % p;
            
            if(mp.find(prevSumMod) != mp.end())
                minLen = min(minLen, i - mp[prevSumMod]);

            mp[currSumMod] = i;
        }

        return minLen == n ? -1 : minLen;
    }
};

/*
# sum of a subarray index-range [i, j]
  = prefixSum[j] - prefixSum[i-1] (if i >= 1)
  or prefixSum[j] (if i == 0)
# let total sum of array = TS, 
  sum of subarray = SS,
  curr prefix sum be CS
  prefixSum[i] be p[i] and
  p[] be the prefixSum of some previous index
# we want to find a subarray of min-length such that:
  (TS - SS) % p = 0 
  (TS - (p[i] - p[])) % p = 0
  (TS % p) - (p[i] % p) + (p[] % p) = 0
  (p[] % p) = (p[i] % p) - (TS % p)
  (p[] % p) = (CS % p) - (TS % p)

# prerequisite: [974. subarray-sums-divisible-by-k]
*/