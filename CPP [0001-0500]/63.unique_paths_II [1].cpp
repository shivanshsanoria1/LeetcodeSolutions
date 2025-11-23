class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) { //T.C.=O(m*n) , S.C.=O(m*n) ; DP
        if(grid[0][0]==1) //cannot reach the end if starting position is an obstacle
            return 0;
        int m= grid.size(), n= grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); //(m+1)*(n+1) dp filled with 0's
        for(int i=1; i<m+1; i++)
            for(int j=1; j<n+1; j++)
            {
                if(grid[i-1][j-1]==1)
                {
                    dp[i][j]=0; //reset dp[i][j]
                    continue;
                }
                if(i==1 && j==1)
                    dp[i][j]=1;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m][n]; //return last element in dp
    }
};
// dp[i][j] is mapped with grid[i-1][j-1]