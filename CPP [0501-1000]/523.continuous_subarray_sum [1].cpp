class Solution {
public:
    // T.C.=O(n), S.C.=O(min(n, k))
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // no subarray of size atleast 2 can be formed
        if(n == 1)
            return false;

        // prefixSum % k -> earliest index
        unordered_map<int, int> mp; 
        // prefixMod is just prefixSum % k
        int prefixMod = 0;

        for(int i=0; i<n; i++)
        {
            prefixMod = (prefixMod + nums[i]) % k;
            
            // i > 0 is used because subarray must be of size atleast 2
            if(prefixMod == 0 && i > 0)
                return true;

            // a subarray with 'prefixMod' was already found
            if(mp.find(prefixMod) != mp.end())
            {
                // check if the index diff between 2 subarrays 
                // with the same 'prefixMod' is >= 2
                if(i - mp.find(prefixMod)->second >= 2)
                    return true;
            }
            // this is the first subarray (starting at index 0) with 'prefixMod'
            else
                mp[prefixMod] = i;
        }

        return false;
    }
};