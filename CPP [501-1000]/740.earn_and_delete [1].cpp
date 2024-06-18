class Solution {
private:
    int solve(unordered_map<int, int>& mp, vector<int>& vec, int prevIdx, int i, vector<vector<int>>& dp){
        if(i >= vec.size())
            return 0;

        if(dp[prevIdx + 1][i] != -1)
            return dp[prevIdx + 1][i];

        int exclude = solve(mp, vec, prevIdx, i+1, dp);

        bool cond = prevIdx == -1 || vec[i] - vec[prevIdx] > 1;
        int include = cond ? vec[i] * mp[vec[i]] + solve(mp, vec, i, i+1, dp) : 0;

        dp[prevIdx + 1][i] = max(include, exclude);
        return dp[prevIdx + 1][i];
    }

public:
    // T.C.=O(n^2), S.C.=O(n^2)
    // DP-Memoization
    int deleteAndEarn(vector<int>& nums) {
        // num -> freq
        unordered_map<int, int> mp; 
        for(int num: nums)
            mp[num]++;
            
        vector<int> vec;
        for(auto [num, freq]: mp)
            vec.push_back(num);
        sort(vec.begin(), vec.end());

        int n=vec.size();
        vector<vector<int>> dp(n+1, vector<int>(n, -1));

        return solve(mp, vec, -1, 0, dp);
    }
};