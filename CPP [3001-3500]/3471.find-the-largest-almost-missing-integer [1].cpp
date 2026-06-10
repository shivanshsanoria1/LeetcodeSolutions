class Solution {
public:
    // T.C.=O(n + 50), S.C.=O(50)
    int largestInteger(vector<int>& nums, int k) {
        // each element in is its own subarray, so return the largest unique num
        if(k == 1)
        {
            vector<int> freq(51, 0);
            for(int num: nums)
                freq[num]++;
            
            for(int i=50; i>=0; i--)
                if(freq[i] == 1)
                    return i;
            
            return -1;
        }

        int n = nums.size();

        // only 1 subarray of size k is possible, so return the max num
        if(k == n)
            return *max_element(nums.begin(), nums.end());

        // only elements at index 0 and n-1 can be the possible ans,
        // since every other indexed element is in multiple subarrays,
        // so find the one which is unique,
        // and then return the one which is maximum
        int ans = -1;

        if(count(nums.begin(), nums.end(), nums[0]) == 1)
            ans = max(ans, nums[0]);
        
        if(count(nums.begin(), nums.end(), nums[n-1]) == 1)
            ans = max(ans, nums[n-1]);
        
        return ans;
    }
};