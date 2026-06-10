class Solution {
private:
    long long int solve(unordered_map<int, int>& mp, vector<int>& nums, int prevIdx, int i){
        if(i >= nums.size())
            return 0;

        long long int exclude = solve(mp, nums, prevIdx, i+1);

        bool cond = prevIdx == -1 || nums[i] - nums[prevIdx] > 2;
        long long int include = cond ? nums[i] * mp[nums[i]] + solve(mp, nums, i, i+1) : 0;

        return max(include, exclude);
    }

public:
    // T.C.=O(2^n)
    // Recursion
    long long maximumTotalDamage(vector<int>& power) {
        // num -> freq
        unordered_map<int, int> mp;
        for(int num: power)
            mp[num]++;
        
        vector<int> nums;
        for(auto [num, freq]: mp)
            nums.push_back(num);
        sort(nums.begin(), nums.end());

        return solve(mp, nums, -1, 0);
    }
};