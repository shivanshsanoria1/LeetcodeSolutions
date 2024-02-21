class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& subset, int i){
        if(i == nums.size())
        {
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        solve(nums, subsets, subset, i+1); // including element at index i
        subset.pop_back();
        // skip all the elements equal to the curr element
        int j = i+1;
        while(j < nums.size() && nums[i] == nums[j])
            j++;
        solve(nums, subsets, subset, j); // excluding element at index i
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) { // Backtracking
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> subset;
        solve(nums, subsets, subset, 0);
        return subsets;
    }
};
/*
# sorting the original array 'nums' ensures that each subset formed is also sorted,
thus avoiding the need to sort each and every subset before adding it to the 'subsets' DS
*/