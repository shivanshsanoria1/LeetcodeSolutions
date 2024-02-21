class Solution {
public:
    int solve(vector<int>& stones, int totalSum, int target, vector<vector<int>>& dp, int i, int currSum){
        if(currSum >= target || i >= stones.size())
            return abs(currSum - (totalSum - currSum)); // diff between the 2 partitions
        if(dp[i][currSum] != -1) // result found in dp
            return dp[i][currSum];
        int include = solve(stones, totalSum, target, dp, i+1, currSum + stones[i]);
        int exclude = solve(stones, totalSum, target, dp, i+1, currSum);
        dp[i][currSum] = min(include, exclude); // store the result in dp
        return dp[i][currSum];
    }

    int lastStoneWeightII(vector<int>& stones) { // Memoization
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        int target = (totalSum + 1) / 2; // basically ceil(totalSum/2)
        vector<vector<int>> dp(stones.size(), vector<int>(totalSum, -1));
        return solve(stones, totalSum, target, dp, 0, 0);
    }
};