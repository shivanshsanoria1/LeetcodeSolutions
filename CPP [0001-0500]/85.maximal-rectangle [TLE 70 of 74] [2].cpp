class Solution {
public:
    // T.C.=O((m*n)^2), S.C.=O(m*n)
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int currVal = matrix[i][j] == '1' ? 1 : 0;
                int pos1 = i-1 >= 0 ? dp[i-1][j] : 0;
                int pos2 = j-1 >= 0 ? dp[i][j-1] : 0;
                int neg1 = i-1 >= 0 && j-1 >= 0 ? dp[i-1][j-1] : 0;
                dp[i][j] = currVal + pos1 + pos2 - neg1;
            }

        int maxArea = 0;

        for(int i1=0; i1<m; i1++)
            for(int j1=0; j1<n; j1++)
            {
                if(matrix[i1][j1] == '0')
                    continue;

                for(int i2=i1; i2<m; i2++)
                    for(int j2=j1; j2<n; j2++)
                    {
                        if(matrix[i2][j2] == '0')
                            continue;

                        int pos1 = dp[i2][j2];
                        int neg1 = j1-1 >= 0 ? dp[i2][j1-1] : 0;
                        int neg2 = i1-1 >= 0 ? dp[i1-1][j2] : 0;
                        int pos2 = i1-1 >= 0 && j1-1 >= 0 ? dp[i1-1][j1-1] : 0;

                        int sum = pos1 - neg1 - neg2 + pos2;

                        if(sum == (i2-i1+1)*(j2-j1+1))
                            maxArea = max(maxArea, sum);
                    }
            }

        return maxArea;
    }
};
// dp[i][j]: sum of all elements in submatrix with 
// top-left corner at (0, 0) and bottom-right corner at (i, j)