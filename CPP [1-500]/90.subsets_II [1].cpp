class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>>& subsets, vector<int>& subset, int i){
        if(i == nums.size())
        {
            subsets.insert(subset);
            return;
        }
        solve(nums, subsets, subset, i+1); // excluding element at index i
        subset.push_back(nums[i]);
        solve(nums, subsets, subset, i+1); // including element at index i
        subset.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) { // Backtracking
        sort(nums.begin(), nums.end());
        set<vector<int>> subsets;
        vector<int> subset;
        solve(nums, subsets, subset, 0);
        vector<vector<int>> ans(subsets.begin(), subsets.end());
        return ans;
    }
};
/*
# eliminate duplicate subsets by using a set DS
# sorting the original array 'nums' ensures that each subset formed is also sorted,
thus avoiding the need to sort each and every subset before adding it to the 'subsets' DS
*/