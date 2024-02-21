class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j){
        int n=matrix.size();
        if(i < 0 || i >= n || j < 0 || j >= n) // index out of bounds
            return INT_MAX;
        if(i == n-1) // last row
            return matrix[i][j];
        if(dp[i][j] != -1) // solution exists in dp
            return dp[i][j];
        int down = solve(matrix, dp, i+1, j);
        int left = solve(matrix, dp, i+1, j-1);
        int right = solve(matrix, dp, i+1, j+1);
        dp[i][j] = matrix[i][j] + min(down, min(left, right));
        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) { // Memoization, T.C.=O(n^2), S.C.=O(n^2)
        int n=matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n-1, vector<int>(n, -1)); // dp of size (n-1)*n filled with -1's
        for(int j=0; j<n; j++) // 0th row
            ans = min(ans, solve(matrix, dp, 0, j));
        return ans;
    }
};