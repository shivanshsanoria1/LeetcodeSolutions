class Solution {
private:
    int solve(vector<int>& nums, unordered_map<int, int>& mp, int i, int k){
        if(i == nums.size())
            return mp.empty() ? 0 : 1;
        
        int exclude = solve(nums, mp, i+1, k);

        int include = 0;
        bool cond1 = mp.find(nums[i] + k) == mp.end();
        bool cond2 = mp.find(nums[i] - k) == mp.end();
        // nums[i] can only be included if (nums[i] + k) and (nums[i] - k) 
        // are not included in the curr-subset
        if(cond1 && cond2)
        {
            mp[nums[i]]++;

            include = solve(nums, mp, i+1, k);

            mp[nums[i]]--;
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
        }

        return exclude + include;
    }

public:
    // T.C.=O(2^n), S.C.=O(n)
    // Backtracking
    int beautifulSubsets(vector<int>& nums, int k) {
        // num -> freq
        unordered_map<int, int> mp;
        return solve(nums, mp, 0, k);
    }
};