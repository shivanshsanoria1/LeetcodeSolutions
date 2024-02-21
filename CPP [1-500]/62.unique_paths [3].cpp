class Solution {
public:
    int uniquePaths(int m, int n) { //DP, T.C.=O(m*n), S.C.=O(m*n)
        vector<vector<int>> dp(m,vector<int>(n,0)); //m*n dp filled with 0's
        for(int i=0; i<m; i++) //fill 0th col with 1's
            dp[i][0]=1;
        for(int j=0; j<n; j++) //fill 0th row with 1's
            dp[0][j]=1;
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1]; //return last element in dp
    }
};