class Solution {
public:
    int climbStairs(int n) { // T.C.=O(n), S.C.=O(n)
        int dp[46]; // since 1<=n<=45 given in ques (index 0 is unused so n=46)
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};