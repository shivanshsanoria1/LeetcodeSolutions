class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // building a new array
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int num: nums)
            ans.push_back(nums[num]);

        return ans;
    }
};