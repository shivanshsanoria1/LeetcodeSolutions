class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& combs, vector<int>& comb, int tar){
        if(tar < 0)
            return;
        if(tar == 0)
        {
            bool combFound = false;
            for(auto vec: combs)
            {
                if(vec.size() != comb.size())
                    continue;
                unordered_map<int, int> mp;
                for(int ele: vec)
                    mp[ele]++;
                for(int ele: comb)
                    mp[ele]--;
                int freq0 = 0;
                for(auto it: mp)
                    if(it.second == 0)
                        freq0++;
                if(freq0 == mp.size())
                {
                    combFound = true;
                    break;
                }
            }
            if(!combFound)
                combs.push_back(comb);
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
        vector<vector<int>> combs;
        vector<int> comb;
        solve(candidates, combs, comb, target);
        return combs;
    }
};