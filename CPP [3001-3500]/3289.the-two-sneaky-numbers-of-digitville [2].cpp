class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for(int i=1; i<nums.size(); i++)
            if(nums[i-1] == nums[i])
            {
                ans.push_back(nums[i]);
                if(ans.size() == 2)
                    break;
            }

        return ans;
    }
};