class Solution {
private:
    int solve(vector<int>& nums, bool player, int i, vector<vector<int>>& dp){
        int n=nums.size();
        if(i >= n)
            return 0;
        
        if(dp[player][i] != -1)
            return dp[player][i];

        int res = player ? INT_MIN : INT_MAX;
        int sum = 0;

        for(int j=0; j<3 && i+j < n; j++)
        {
            sum += nums[i+j];

            // Alice is trying to maximize her score
            if(player)
                res = max(res, sum + solve(nums, !player, i+j+1, dp));
            // Bob is trying to minimize Alice's score
            else
                res = min(res, solve(nums, !player, i+j+1, dp));
        }

        dp[player][i] = res;
        return dp[player][i];
    }

public:
    // T.C.=O(n), S.C.=O(2*n)
    // DP: Memoization
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>> dp(2, vector<int>(n, -1));

        int totalSum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int scoreA = solve(stoneValue, true, 0, dp);
        int scoreB = totalSum - scoreA;

        if(scoreA == scoreB)
            return "Tie";
        
        return scoreA > scoreB ? "Alice" : "Bob";
    }
};