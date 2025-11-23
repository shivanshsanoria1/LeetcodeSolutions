class Solution {
public:
    void solve(vector<vector<int>>& perms, vector<int>& nums, int idx){
        if(idx == nums.size())
        {
            perms.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            solve(perms, nums, idx + 1);
            swap(nums[idx], nums[i]); 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) { // Backtracking, T.C.=O(n*n!), S.C.=O(n)
        vector<vector<int>> perms;
        solve(perms, nums, 0);
        return perms;
    }
};