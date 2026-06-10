class Solution {
private:
    typedef long long int lli;

    lli solve(unordered_map<int, int>& mp, vector<int>& nums, int prevIdx, int i, vector<vector<lli>>& dp){
        if(i >= nums.size())
            return 0;

        if(dp[prevIdx + 1][i] != -1)
            return dp[prevIdx + 1][i];

        lli exclude = solve(mp, nums, prevIdx, i+1, dp);

        bool cond = prevIdx == -1 || nums[i] - nums[prevIdx] > 2;
        lli include = cond ? nums[i] * mp[nums[i]] + solve(mp, nums, i, i+1, dp) : 0;

        dp[prevIdx + 1][i] = max(include, exclude);
        return dp[prevIdx + 1][i]; 
    }

public:
    // T.C.=O(n^2), S.C.=O(n^2)
    // DP-Memoization
    long long maximumTotalDamage(vector<int>& power) {
        // num -> freq
        unordered_map<int, int> mp;
        for(int num: power)
            mp[num]++;
        
        vector<int> nums;
        for(auto [num, freq]: mp)
            nums.push_back(num);
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        vector<vector<lli>> dp(n+1, vector<lli>(n, -1));

        return solve(mp, nums, -1, 0, dp);
    }
};