class Solution {
private:
    typedef long long int lli;

public:
    long long mostPoints(vector<vector<int>>& questions) { // DP, T.C.=O(n), S.C.=O(n)
        int n=questions.size();
        vector<lli> dp(n);
        // if we are at last index then it must be solved
        dp[n-1] = questions[n-1][0];
        for(int i=n-2; i>=0; i--)
        {
            // solve the ith question
            lli solve = questions[i][0]; 
            if(i + 1 + questions[i][1] < n)
                solve += dp[i + 1 + questions[i][1]];
            // skip the ith question
            lli skip = dp[i + 1];
            dp[i] = max(solve, skip);
        }
        return dp[0];
    }
};
/*
# dp[i]: max points gained starting at index i
# questions[i][0]: curr points
# questions[i][1]: num of indexes to skip if curr ques is solved
*/