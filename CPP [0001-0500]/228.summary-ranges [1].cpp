class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        int start = 0, end = 0;
        for(int i=0; i<n; i++)
        {
            if(i+1 < n && nums[i+1] == nums[i] + 1)
                end++;
            else
            {
                if(start == end)
                    ans.push_back(to_string(nums[start]));
                else
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                start = i + 1;
                end = i + 1;
            }
        }
        return ans;
    }
};