class Solution {
public:
    int uniquePaths(int m, int n) { //T.C.=O(m*n) , S.C.=O(m*n) ; DP
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); //(m+1)*(n+1) dp filled with 0's
        for(int i=1; i<m+1; i++)
            for(int j=1; j<n+1; j++)
            {
                if(i==1 && j==1)
                    dp[i][j]=1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m][n]; //return last element in dp
    }
};