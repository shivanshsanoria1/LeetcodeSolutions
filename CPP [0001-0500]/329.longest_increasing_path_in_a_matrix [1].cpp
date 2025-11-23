class Solution {
public:
    // retuns the length of the longest strictly increasing path starting at (i, j) 
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int parVal){
        int m=matrix.size(), n=matrix[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n) // index out of bounds
            return 0;
        // parent value exists and curr val <= par val, ie, invalid path
        if(parVal != -1 && matrix[i][j] <= parVal)
            return 0;
        if(dp[i][j] > 0) // solution already present in dp
            return dp[i][j];
        int up = dfs(matrix, dp, i-1, j, matrix[i][j]);
        int down = dfs(matrix, dp, i+1, j, matrix[i][j]);
        int left = dfs(matrix, dp, i, j-1, matrix[i][j]);
        int right = dfs(matrix, dp, i, j+1, matrix[i][j]);
        dp[i][j] = 1 + max(max(up, down), max(left, right)); // store the result in dp
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) { // T.C.=O(m*n), S.C.=O(m*n)
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp of size m*n filled with 0's
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                dp[i][j] = dfs(matrix, dp, i, j, -1);
                ans = max(ans, dp[i][j]);
            }
        return ans;
    }
};