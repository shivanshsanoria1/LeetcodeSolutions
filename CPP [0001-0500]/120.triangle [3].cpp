class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) { // DP
        int m=triangle.size();
        int nLast = triangle[m-1].size(); // size of last row
        // dp of size 2*(size of last row of input array) filled with -1's
        vector<vector<int>> dp(2, vector<int>(nLast, -1));
        // fill both the rows of dp with the last row of input array
        for(int j=0; j<nLast; j++)
        {
            dp[0][j] = triangle[m-1][j]; // to handle the case where m=1
            dp[1][j] = triangle[m-1][j];
        }
        for(int i=m-2; i>=0; i--)
        {
            int n=triangle[i].size();
            // fill the 0th row with 1st row in dp (from col 0 to n)
            for(int j=0; j<n; j++)
            {
                int down = dp[1][j];
                int right = j < n ? dp[1][j+1] : INT_MAX;
                dp[0][j] = triangle[i][j] + min(down, right);
            }
            // copy the 0th row to the 1st row in dp (from col 0 to n)
            for(int j=0; j<n; j++)
                dp[1][j] = dp[0][j];
        }
        return dp[0][0];
    }
};