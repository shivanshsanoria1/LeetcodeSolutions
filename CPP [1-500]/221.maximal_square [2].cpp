class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) { //T.C.=O(m*n) , S.C.=O(m*n) ; DP
        int m= matrix.size(), n= matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1,0)); //dp of size (m+1)*(n+1) filled with 0's
        int max_square=0;
        for(int i=1; i<m+1; i++)
            for(int j=1; j<n+1; j++)
            {
                if(matrix[i-1][j-1] == '0') //skip the 0's
                    continue;
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                max_square = max(max_square,dp[i][j]);
            }
        return max_square*max_square;
    }
};
// dp[i][j] is mapped with matrix[i-1][j-1]
// dp[i][j] = 1 + min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])
