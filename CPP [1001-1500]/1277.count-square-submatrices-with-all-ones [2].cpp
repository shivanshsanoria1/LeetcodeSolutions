class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // DP: Tabulation
    int countSquares(vector<vector<int>>& matrix) { 
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 0th row of dp[][] is the same as matrix[][]
        for(int j=0; j<n; j++) 
            dp[0][j] = matrix[0][j];
        // 0th col of dp[][] is the same as matrix[][]
        for(int i=0; i<m; i++)
            dp[i][0] = matrix[i][0];

        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j] == 0)
                    continue;
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        
        int count = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)  
                count += dp[i][j];
        
        return count;
    }
};

// dp[i][j] is max size of the square with bottom-right corner at (i, j) 