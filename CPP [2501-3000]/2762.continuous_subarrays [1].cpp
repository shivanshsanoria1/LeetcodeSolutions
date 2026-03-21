class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n), sliding-window
    long long continuousSubarrays(vector<int>& nums) { 
        map<int, int> mp;
        long long int count = 0;
        int n=nums.size();
        int left = 0, right = 0;
        while(right < n)
        {
            mp[nums[right]]++;
            int minVal = mp.begin()->first;
            int maxVal = mp.rbegin()->first;
            // reduce the window size until the window becomes valid 
            while(maxVal - minVal > 2)
            {
                mp[nums[left]]--;
                // remove the element at 'left' if its freq reaches 0 
                if(mp[nums[left]] == 0)
                {
                    mp.erase(nums[left]);
                    // update the max and min values in the curr window
                    minVal = mp.begin()->first;
                    maxVal = mp.rbegin()->first;
                }
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};