class Solution {
public:
    // T.C.=O((m*n)^2), S.C.=O(m*n)
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();

        // dp[i][j]: sum of all elements in the submatrix with
        // top-left corner at (0, 0) and bottom-right corner at (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int north = i-1 >= 0 ? dp[i-1][j] : 0;
                int west = j-1 >= 0 ? dp[i][j-1] : 0;
                int northWest = i-1 >= 0 && j-1 >= 0 ? dp[i-1][j-1] : 0;

                dp[i][j] = mat[i][j] + north + west - northWest;
            }

        int count = 0;

        // check for each submatrix with top-left corner at (i1, j1)
        // and bottom-right corner at (i2, j2)
        for(int i1=0; i1<m; i1++)
            for(int j1=0; j1<n; j1++)
                for(int i2=i1; i2<m; i2++)
                    for(int j2=j1; j2<n; j2++)
                    {
                        int pos1 = dp[i2][j2];
                        int neg1 = i1-1 >= 0 ? dp[i1-1][j2] : 0;
                        int neg2 = j1-1 >= 0 ? dp[i2][j1-1] : 0;
                        int pos2 = i1-1 >= 0 && j1-1 >= 0 ? dp[i1-1][j1-1] : 0;
                        
                        // num of elements in submatrix
                        int submatrixCount = (i2-i1+1)*(j2-j1+1);

                        // invalid submatrix
                        if(pos1 - neg1 - neg2 + pos2 != submatrixCount)
                            break;
                            
                        count++;
                    }

        return count;
    }
};