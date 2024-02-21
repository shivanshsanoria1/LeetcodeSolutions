class Solution {
public:
    long long countBadPairs(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> mp; // (nums[i] - i) -> freq
        long long int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i] - i) != mp.end()) // found in map
                count += i - mp[nums[i] - i];
            else // not found in map
                count += i;
            mp[nums[i] - i]++;
        }
        return count;
    }
};