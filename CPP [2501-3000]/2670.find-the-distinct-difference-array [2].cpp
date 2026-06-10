class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> prefix, suffix;
        for(int num: nums)
            suffix[num]++;
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            prefix[nums[i]]++;
            suffix[nums[i]]--;
            if(suffix[nums[i]] == 0)
                suffix.erase(nums[i]);
            ans[i] = prefix.size() - suffix.size();
        }
        return ans;
    }
};