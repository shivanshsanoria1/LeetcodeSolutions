class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // DP-Tabulation
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0)); 

        int maxSideLen = 0;

        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {
                if(matrix[i-1][j-1] == '0')
                    continue;

                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));

                maxSideLen = max(maxSideLen, dp[i][j]);
            }

        return maxSideLen * maxSideLen;
    }
};
// dp[i][j] is mapped with matrix[i-1][j-1]
// 1 extra row and col for 0-padding in dp
