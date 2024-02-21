class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& combs, vector<int>& comb, int tar, int i){
        if(i >= nums.size()) // index out of bounds
            return;
        if(tar < 0) // reached over the target
            return;
        if(tar == 0) // reached target
        {
            combs.push_back(comb);
            return;
        }
        // pick the element at index i, ie, remain at the same index (so that nums[i] can possibly be picked again)
        comb.push_back(nums[i]);
        solve(nums, combs, comb, tar - nums[i], i);
        comb.pop_back();
        // not pick the element at index i, ie, move to the next index (so that nums[i] can never be picked again)
        solve(nums, combs, comb, tar, i+1); 
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combs;
        vector<int> comb;
        solve(candidates, combs, comb, target, 0);
        return combs;
    }
};