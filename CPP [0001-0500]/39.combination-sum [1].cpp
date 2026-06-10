class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& combs, vector<int>& comb, int target, int i){
        // reached over the target
        if(target < 0) 
            return;
        // reached the target
        if(target == 0) 
        {
            combs.push_back(comb);
            return;
        }
        // index out of bounds
        if(i >= nums.size()) 
            return;

        // skip the element at index i, ie, move to the next index 
        // (so that nums[i] can never be picked again)
        solve(nums, combs, comb, target, i+1); 

        // pick the element at index i, ie, remain at the same index 
        // (so that nums[i] can possibly be picked again)
        comb.push_back(nums[i]);
        solve(nums, combs, comb, target - nums[i], i);
        comb.pop_back();
    }

public:
    // Backtracking
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combs;
        vector<int> comb;
        solve(candidates, combs, comb, target, 0);

        return combs;
    }
};