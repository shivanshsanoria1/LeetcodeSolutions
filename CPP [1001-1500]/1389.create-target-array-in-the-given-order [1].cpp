class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            ans.push_back(-1);
            for(int j = ans.size()-2; j >= index[i]; j--)
                ans[j+1] = ans[j];
            ans[index[i]] = nums[i];
        }
        return ans;
    }
};