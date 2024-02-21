class Solution {
public:
    void solve(vector<int>& nums, set<vector<int>>& combs, vector<int>& comb, int tar){
        if(tar < 0)
            return;
        if(tar == 0)
        {
            // create a copy of comb vector
            vector<int> tempComb(comb.begin(), comb.end());
            // sort this copied version of comb before inserting it in the set
            sort(tempComb.begin(), tempComb.end());
            combs.insert(tempComb);
            return;
        }
        for(int num: nums)
        {
            comb.push_back(num);
            solve(nums, combs, comb, tar - num);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        set<vector<int>> combs;
        solve(candidates, combs, comb, target);
        vector<vector<int>> ans(combs.begin(), combs.end());
        return ans;
    }
};