class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> mp; // target num -> freq
        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] == key)
                mp[nums[i]]++;

        int maxFreq = 0;
        int ans = 0;
        for(auto [num, freq]: mp)
            if(freq > maxFreq)
            {
                maxFreq = freq;
                ans = num;
            }
        return ans;
    }
};