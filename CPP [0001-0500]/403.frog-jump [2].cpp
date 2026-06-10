class Solution {
public:
    bool solve(vector<int>& stones, unordered_map<int, int>& mp, vector<vector<int>>& dp, int i, int jump){
        if(i == stones.size() - 1)
            return true;
        if(jump <= 0)
            return false;
        if(mp.find(stones[i] + jump) == mp.end())
            return false;

        if(dp[i][jump] != -1)
            return dp[i][jump];

        int idx = mp[stones[i] + jump];
        bool j1 = solve(stones, mp, dp, idx, jump - 1);
        bool j2 = solve(stones, mp, dp, idx, jump);
        bool j3 = solve(stones, mp, dp, idx, jump + 1);

        dp[i][jump] = j1 || j2 || j3;
        return dp[i][jump];
    }

    bool canCross(vector<int>& stones) { // Memoization, T.C.=O(n^2), S.C.=O(n^2)
        int n=stones.size();
        unordered_map<int, int> mp; // stone -> index
        for(int i=0; i<n; i++)
            mp[stones[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(stones, mp, dp, 0, 1);
    }
};