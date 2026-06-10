class Solution {
private:
    typedef long long int lli;

public:
    lli dfs(vector<vector<int>>& questions, vector<lli>& dp, int i){
        if(i >= questions.size()) // index out of bounds
            return 0;
        if(dp[i] != -1) // solution exists in dp
            return dp[i];
        // solve the ith question
        lli solve = questions[i][0] + dfs(questions, dp, i + 1 + questions[i][1]);
        // skip the ith question
        lli skip = dfs(questions, dp, i + 1);
        dp[i] = max(solve, skip); // store the solution for index i in dp
        return dp[i];
    }

    long long mostPoints(vector<vector<int>>& questions) { // Memoization, T.C.=O(n), S.C.=O(n)
        vector<lli> dp(questions.size(), -1);
        return dfs(questions, dp, 0);
    }
};