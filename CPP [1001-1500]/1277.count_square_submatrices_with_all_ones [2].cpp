class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) { // T.C.=O(m*n), S.C.=O(m*n), DP
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0)); // dp of size m*n filled with 0's
        int count = 0;
        for(int j=0; j<n; j++) // 0th row
        {
            dp[0][j] = matrix[0][j];
            count += dp[0][j];
        }
        for(int i=0; i<m; i++) // 0th col
        {
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }
        if(dp[0][0] == 1) // since dp[0][0] is counted in both 0th row and 0th col
            count--;
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j] == 0) // skip the 0's in matrix
                    continue;
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                count += dp[i][j];
            }
        return count;
    }
};
// dp[i][j] is max size of the square with bottom-right corner at (i,j) 