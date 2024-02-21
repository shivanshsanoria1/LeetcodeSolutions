class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n), similar to bubble-sort
    bool canSortArray(vector<int>& nums) {
        unordered_map<int, int> mp; // num -> set bit count
        for(int num: nums)
            if(mp.find(num) == mp.end()) // not found in map
                mp[num] = __builtin_popcount(num);

        int n=nums.size();
        for(int i=0; i<n-1; i++)
        {
            bool swapped = false;
            for(int j=0; j<n-1-i; j++)
                if(mp[nums[j]] == mp[nums[j+1]] && nums[j] > nums[j+1])
                {
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            if(!swapped)
                break;
        }

        for(int i=1; i<n; i++)
            if(nums[i-1] > nums[i])
                return false;
        return true;
    }
};