class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int maxBalancedSubarray(vector<int>& nums) {
        int prefixSum = 0;
        int prefixXor = 0;
        int maxLen = 0;
        // (prefixSum, prefixXor) -> smallest idx
        unordered_map<string, int> mp;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i] % 2 == 0 ? 1 : -1;
            prefixXor ^= nums[i];

            string hash = to_string(prefixSum) + "#" + to_string(prefixXor);

            // the subarray [0, i] is already valid
            // no need to search for any previous matching pair
            if(hash == "0#0"){
                maxLen = i+1;
                continue;
            }

            // matching pair already found previously
            // subarray [mp[hash] + 1, i] is valid
            if(mp.find(hash) != mp.end())
                maxLen = max(maxLen, i - mp[hash]);
            // add the new pair in map
            else
                mp[hash] = i;
        }

        return maxLen;
    }
};