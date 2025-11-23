class Solution {
private:
    void solve(vector<int>& nums, set<vector<int>>& combs, vector<int>& comb, int target, int i){
        // reached over the target
        if(target < 0) 
            return;
        // reached the target
        if(target == 0) 
        {
            combs.insert(comb);
            return;
        }
        // index out of bounds
        if(i >= nums.size()) 
            return;

        // pick the element at index i
        comb.push_back(nums[i]);
        solve(nums, combs, comb, target - nums[i], i+1);
        comb.pop_back();

        // not pick the element at index i
        solve(nums, combs, comb, target, i+1); 
    }

public:
    // Backtracking
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        set<vector<int>> combs;
        vector<int> comb;
        solve(candidates, combs, comb, target, 0);

        vector<vector<int>> ans(combs.begin(), combs.end());
        return ans;
    }
};