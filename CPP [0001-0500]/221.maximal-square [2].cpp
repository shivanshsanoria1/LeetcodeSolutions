class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // DP-Tabulation
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxSideLen = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                
                int north = i-1 >= 0 ? dp[i-1][j] : 0;
                int west = j-1 >= 0 ? dp[i][j-1] : 0;
                int northWest = i-1 >= 0 && j-1 >= 0 ? dp[i-1][j-1] : 0;

                dp[i][j] = 1 + min(northWest, min(north, west));

                maxSideLen = max(maxSideLen, dp[i][j]);
            }

        return maxSideLen * maxSideLen;
    }
};
// dp[i][j]: max side length of square with bottom-right corner at (i, j) 