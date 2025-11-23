class Solution {
public:
    bool solve(string& s,  vector<vector<int>>& dp, int i, int count){
        if(i == s.length()) // reached the end of string
            return count == 0 ? true : false;
        if(count < 0) // more ')' than '('
            return false;
        if(dp[i][count] != -1) // solution already exists in dp
            return dp[i][count];
        if(s[i] == '(')
        {
            dp[i][count] = solve(s, dp, i+1, count + 1);
            return dp[i][count];
        }
        if(s[i] == ')')
        {
            dp[i][count] = solve(s, dp, i+1, count - 1);
            return dp[i][count];
        }
        // treat '*' as '('
        bool left = solve(s, dp, i+1, count + 1);
        if(left)
        {
            dp[i][count] = true;
            return dp[i][count];
        }
        // treat '*' as ')'
        bool right = solve(s, dp, i+1, count - 1);
        if(right)
        {
            dp[i][count] = true;
            return dp[i][count];
        }
        // treat '*' as ''
        bool skip = solve(s, dp, i+1, count);
        if(skip)
        {
            dp[i][count] = true;
            return dp[i][count];
        }
        // string from index [0,i] cannot be balanced
        dp[i][count] = false;
        return dp[i][count];
    }

    bool checkValidString(string s) { // Memoization, T.C.=O(n^2), S.C.=O(n^2)
        int n=s.length();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(s, dp, 0, 0);
    }
};
/*
# count: keeps track of num of '(' which do not have a matching ')'
# dp[i][count]: string ending at index i having 'count' is valid or not
# dp[i][count] = -1: no solution found yet
# dp[i][count] = 0: false
# dp[i][count] = 1: true
*/