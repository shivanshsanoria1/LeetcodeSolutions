class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) { // DP, T.C.=O(n^2), S.C.=O(n^2)
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n)); // dp of size n*n
        for(int j=0; j<n; j++) // last row
            dp[n-1][j] = matrix[n-1][j];
        for(int i=n-2; i>=0; i--)
            for(int j=0; j<n; j++)
            {
                int left = j-1 >= 0 ? dp[i+1][j-1] : INT_MAX;
                int right = j+1 < n ? dp[i+1][j+1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(dp[i+1][j], min(left, right));
            }
        int ans = INT_MAX;
        for(int j=0; j<n; j++) // 0th row
            ans = min(ans, dp[0][j]);
        return ans;
    }
};