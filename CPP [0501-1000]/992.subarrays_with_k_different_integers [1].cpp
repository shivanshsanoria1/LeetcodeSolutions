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

public:
    // T.C.=O(n), S.C.=O(n)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count1 = subarraysWithLessThanEqual_K_Distinct(nums, k);
        int count2 = subarraysWithLessThanEqual_K_Distinct(nums, k-1);

        return count1 - count2;
    }
};
/*
# { num of subarrays with exactly K distinct elements } = 
  { num of subarrays with [0, k] distinct elements } - 
  { num of subarrays with [0, k) distinct elements }
*/