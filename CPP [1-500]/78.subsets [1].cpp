class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& subset, int i){
        if(i == nums.size())
        {
            subsets.push_back(subset);
            return;
        }
        solve(nums, subsets, subset, i+1); // excluding element at index i
        subset.push_back(nums[i]);
        solve(nums, subsets, subset, i+1); // including element at index i
        subset.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) { // Backtracking
        vector<vector<int>> subsets;
        vector<int> subset;
        solve(nums, subsets, subset, 0);
        return subsets;
    }
};