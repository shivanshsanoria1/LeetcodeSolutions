class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) { //T.C.=O(m*n) , S.C.=O(m*n) ; DP
        if(grid[0][0]==1) //cannot reach the end if starting position is an obstacle
            return 0;
        int m= grid.size(), n= grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0)); //m*n dp filled with 0's
        dp[0][0]=1; //num of ways to reach from (0,0) to (0,0) is 1
        for(int i=1; i<m; i++) //fill 0th col
            dp[i][0] = (grid[i][0]==0 && dp[i-1][0]==1) ? 1 : 0;
        for(int j=1; j<n; j++) //fill 0th row
            dp[0][j] = (grid[0][j]==0 && dp[0][j-1]==1) ? 1 : 0;
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
            {
                if(grid[i][j]==1)
                    dp[i][j] = 0; //reset dp[i][j]
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m-1][n-1]; //return last element in dp
    }
};
