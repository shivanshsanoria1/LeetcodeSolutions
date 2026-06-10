class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++) // using nums[] as prefix sum array
            nums[i] += nums[i-1];
        vector<int> ans;
        for(int qu: queries)
        {
            int idx = upper_bound(nums.begin(), nums.end(), qu) - nums.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};