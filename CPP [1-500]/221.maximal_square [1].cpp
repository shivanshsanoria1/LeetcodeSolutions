class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) { //T.C.=O(m*n) , S.C.=O(m*n) ; DP
        int m= matrix.size(), n= matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0)); //dp of size m*n filled with 0's
        
        for(int i=0; i<m; i++) //fill the 0th col
            dp[i][0] = matrix[i][0] - '0';
        for(int j=0; j<n; j++) //fill the 0th row
            dp[0][j] = matrix[0][j] - '0';
        
        int max_square=0;
        for(int i=0; i<m; i++) //check the 0th col
            if(dp[i][0] == 1)
                max_square=1;
        if(max_square == 0)
            for(int j=0; j<n; j++) //check the 0th row
                if(dp[0][j] == 1)
                    max_square=1;
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j] == '0') //skip the 0's
                    continue;
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                max_square = max(max_square,dp[i][j]);
            }
        return max_square*max_square;
    }
};
// dp[i][j] = 1 + min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])
