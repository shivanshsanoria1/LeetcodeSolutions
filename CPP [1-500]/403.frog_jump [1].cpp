class Solution {
public:
    bool solve(vector<int>& stones, unordered_map<int, int>& mp, vector<unordered_map<int, int>>& dp, int i, int jump){
        if(i == stones.size() - 1)
            return true;
        if(jump <= 0)
            return false;
        if(mp.find(stones[i] + jump) == mp.end()) // not found in map
            return false;

        if(dp[i].find(jump) != dp[i].end()) // ans already in map
            return dp[i][jump];

        int idx = mp[stones[i] + jump];
        bool j1 = solve(stones, mp, dp, idx, jump - 1);
        bool j2 = solve(stones, mp, dp, idx, jump);
        bool j3 = solve(stones, mp, dp, idx, jump + 1);

        dp[i][jump] = j1 || j2 || j3;
        return dp[i][jump];
    }

    bool canCross(vector<int>& stones) { // Memoization
        int n=stones.size();
        unordered_map<int, int> mp; // stone -> index
        for(int i=0; i<n; i++)
            mp[stones[i]] = i;
        vector<unordered_map<int, int>> dp(n); // i -> { jump -> ans }
        return solve(stones, mp, dp, 0, 1);
    }
};