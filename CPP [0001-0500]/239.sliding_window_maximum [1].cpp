class Solution {
public:
    // T.C.=O(n*log(k)), S.C.=O(k)
    // Sliding-Window (fixed-size)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // num -> freq
        map<int, int> mp;
        // push the elements in 1st window, 
        // ie, in index range [0, k-1]
        for(int i=0; i<k; i++)
            mp[nums[i]]++;

        vector<int> ans;
        ans.push_back(mp.rbegin()->first);

        int left = 1, right = k;
        while(right < nums.size())
        {
            mp[nums[left - 1]]--;
            if(mp[nums[left - 1]] == 0)
                mp.erase(nums[left - 1]);

            mp[nums[right]]++;
            
            ans.push_back(mp.rbegin()->first);

            left++;
            right++;
        }

        return ans;
    }
};