class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>>& combs, vector<int>& comb, int tar, int i){
        if(tar < 0) // reached over the target
            return;
        if(tar == 0) // reached target
        {
            combs.insert(comb);
            return;
        }
        if(i >= nums.size()) // index out of bounds
            return;
        // pick the element at index i
        comb.push_back(nums[i]);
        solve(nums, combs, comb, tar - nums[i], i+1);
        comb.pop_back();
        // not pick the element at index i
        solve(nums, combs, comb, tar, i+1); 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> combs;
        vector<int> comb;
        solve(candidates, combs, comb, target, 0);
        vector<vector<int>> ans(combs.begin(), combs.end());
        return ans;
    }
};