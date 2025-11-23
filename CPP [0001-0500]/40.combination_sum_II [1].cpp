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

        // pick the element at index i
        comb.push_back(nums[i]);
        solve(nums, combs, comb, target - nums[i], i+1);
        comb.pop_back();

        // skip the adjacent duplicates
        while(i+1 < nums.size() && nums[i] == nums[i+1])
            i++;
        // skip the element at index i
        solve(nums, combs, comb, target, i+1); 
    }

public:
    // T.C.=O(n*log(n) + n*2^n), S.C.=O(n)
    // Backtracking
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> combs;
        vector<int> comb;
        solve(candidates, combs, comb, target, 0);

        return combs;
    }
};
/*
# if we pick the element at index i, then we can possibly 
  pick its duplicates at index i+1, i+2, ...
# but if we skip the element at index i, then we must also 
  skip all of its duplicates at index i+1, i+2, ...
*/