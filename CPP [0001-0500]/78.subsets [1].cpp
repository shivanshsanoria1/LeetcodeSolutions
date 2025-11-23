class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& subset, int i){
        if(i == nums.size())
        {
            subsets.push_back(subset);
            return;
        }

        // exclude
        solve(nums, subsets, subset, i+1);

        // include
        subset.push_back(nums[i]);
        solve(nums, subsets, subset, i+1);
        subset.pop_back();
    }

public:
    // T.C.=O(n * 2^n), S.C.=O(n)
    // Backtracking
    vector<vector<int>> subsets(vector<int>& nums) { 
        vector<vector<int>> subsets;
        vector<int> subset;
        solve(nums, subsets, subset, 0);
        return subsets;
    }
};