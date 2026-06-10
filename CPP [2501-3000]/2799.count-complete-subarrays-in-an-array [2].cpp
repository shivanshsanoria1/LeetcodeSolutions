class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> mp; // num -> freq
        for(int num: nums)
            mp[num]++;
        int distinct = mp.size();
        mp.clear();

        int n=nums.size();
        int left = 0, right = 0;
        int count = 0;
        while(right < n)
        {
            mp[nums[right]]++;

            while(mp.size() == distinct)
            {
                count += n - right;
                mp[nums[left]]--;
                if(mp[nums[left]] == 0)
                    mp.erase(nums[left]);
                left++;
            }

            right++;
        }
        return count;
    }
};