class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int findMaxLength(vector<int>& nums) {
        // zeros count - ones count -> index
        unordered_map<int, int> mp;
        int zeros = 0, ones = 0;
        int maxLen = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                zeros++;
            else // nums[i] == 1
                ones++;
            
            int diff = zeros - ones;
            // only add new diff to map
            if(mp.find(diff) == mp.end())
                mp[diff] = i;

            // subarray from index [0, i] is valid
            if(diff == 0)
                maxLen = max(maxLen, i + 1);
            // subarray from index [mp[diff] + 1, i] is valid
            else
                maxLen = max(maxLen, i - mp[diff]);
        }
        return maxLen;
    }
};