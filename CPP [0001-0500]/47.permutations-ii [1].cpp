class Solution {
public:
    void solve(vector<int>& nums, int left, int right, set<vector<int>>& s, vector<vector<int>>& ans)
    {
        if(left == right && s.find(nums)==s.end()) //vector nums not present in set
        {
            ans.push_back(nums);
            s.insert(nums);
            return;
        }
        for(int i=left; i<=right; i++)
        {
            swap(nums[left],nums[i]);
            solve(nums,left+1,right,s,ans);
            swap(nums[left],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n=nums.size();
        solve(nums,0,n-1,s,ans); //initially left=0, right= n-1
        return ans;
    }
};