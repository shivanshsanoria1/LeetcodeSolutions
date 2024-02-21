class Solution {
public:
    // T.C.=O((m*n)^2), S.C.=O(m*n)
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        // preSum[i][j]: sum of all elements in the submatrix with 
        // top-left corner at (0,0) and bottom-right corner at (i,j)
        vector<vector<int>> preSum(m, vector<int>(n, 0));
        // (0,0)
        preSum[0][0] = matrix[0][0];
        // 0th row
        for(int j=1; j<n; j++)
            preSum[0][j] = matrix[0][j] + preSum[0][j-1];
        // 0th col
        for(int i=1; i<m; i++)
            preSum[i][0] = matrix[i][0] + preSum[i-1][0];
        // all the rows and cols except 0th row and 0th col
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                preSum[i][j] = matrix[i][j] + preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1];

        // check for each submatrix with 
        // top-left corner at (i1,j1) and bottom-right corner at (i2,j2)
        int count = 0;
        for(int i1=0; i1<m; i1++)
            for(int j1=0; j1<n; j1++)
                for(int i2=i1; i2<m; i2++)
                    for(int j2=j1; j2<n; j2++)
                    {
                        int pos1 = preSum[i2][j2];
                        int neg1 = i1-1 >= 0 ? preSum[i1-1][j2] : 0;
                        int neg2 = j1-1 >= 0 ? preSum[i2][j1-1] : 0;
                        int pos2 = i1-1 >= 0 && j1-1 >= 0 ? preSum[i1-1][j1-1] : 0;
                        if(pos1 - neg1 - neg2 + pos2 == target)
                            count++;
                    }
        return count;
    }
};