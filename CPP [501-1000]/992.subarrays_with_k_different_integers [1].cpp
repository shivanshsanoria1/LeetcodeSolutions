class Solution {
private:
    // returns num of subarrays with <= K distinct nums
    int subarraysWithLessThanEqual_K_Distinct(vector<int>& nums, int k) {
        // num -> freq
        unordered_map<int, int> mp;

        int left = 0, right = 0;
        int count = 0;

        while(right < nums.size())
        {
            // increase the window size
            mp[nums[right]]++;

            // shrink the window size until it becomes valid
            while(mp.size() > k)
            {
                mp[nums[left]]--;

                // remove the element from map if its freq reaches 0
                if(mp[nums[left]] == 0)
                    mp.erase(nums[left]);

                left++;
            }

            // increment count with the curr window size
            count += right - left + 1;

            right++;
        }
        
        return count;
    }

    // returns num of subarrays with < K distinct nums
    int subarraysWithLessThan_K_Distinct(vector<int>& nums, int k) {
        // num -> freq
        unordered_map<int, int> mp;
        
        int left = 0, right = 0;
        int count = 0;

        while(right < nums.size())
        {
            // increase the window size
            mp[nums[right]]++;

            // shrink the window size until it becomes valid
            while(mp.size() >= k)
            {
                mp[nums[left]]--;

                // remove the element from map if its freq reaches 0
                if(mp[nums[left]] == 0)
                    mp.erase(nums[left]);

                left++;
            }

            // increment count with the curr window size
            count += right - left + 1;

            right++;
        }
        
        return count;
    }

public:
    // T.C.=O(n), S.C.=O(n)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithLessThanEqual_K_Distinct(nums, k) - subarraysWithLessThan_K_Distinct(nums, k);
    }
};