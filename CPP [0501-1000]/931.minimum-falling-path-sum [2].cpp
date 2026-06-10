class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) { // DP, T.C.=O(n^2), S.C.=O(2*n)
        int n=matrix.size();
        vector<vector<int>> dp(2, vector<int>(n)); // dp of size 2*n
        for(int j=0; j<n; j++) // last row
        {
            dp[0][j] = matrix[n-1][j]; // required for the case where n=1
            dp[1][j] = matrix[n-1][j];
        }
        for(int i=n-2; i>=0; i--)
        {
            // use the 1st row to fill the 0th row of dp
            for(int j=0; j<n; j++)
            {
                int left = j-1 >= 0 ? dp[1][j-1] : INT_MAX;
                int right = j+1 < n ? dp[1][j+1] : INT_MAX;
                dp[0][j] = matrix[i][j] + min(dp[1][j], min(left, right));
            }
            // copy the 0th row to the 1st row of dp
            for(int j=0; j<n; j++)
                dp[1][j] = dp[0][j];
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++) // 0th row
            ans = min(ans, dp[0][j]);
        return ans;
    }
};