class Solution {
public:
    void solve(vector<vector<int>>& combs, vector<int>& comb, int start, int target, int height){
        if(height == 0)
        {
            if(target == 0)
                combs.push_back(comb);
            return;
        }
        // reached over the target or reached the target before reaching height 0
        if(target <= 0)
            return;
        for(int i=start; i<=9; i++)
        {
            comb.push_back(i);
            solve(combs, comb, i + 1, target - i, height - 1);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combs;
        vector<int> comb;
        solve(combs, comb, 1, n, k);
        return combs;
    }
};