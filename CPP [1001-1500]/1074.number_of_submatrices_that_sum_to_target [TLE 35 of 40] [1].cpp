class Solution {
private:
    int calculateSum(vector<vector<int>>& matrix, int r1, int c1, int r2, int c2){
        int sum = 0;
        for(int i=r1; i<=r2; i++)
            for(int j=c1; j<=c2; j++)
                sum += matrix[i][j];
        return sum;
    }

public:
    // T.C.=O((m*n)^3), S.C.=O(1)
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        // check for each submatrix with 
        // top-left corner at (i1,j1) and bottom-right corner at (i2,j2)
        int count = 0;
        for(int i1=0; i1<m; i1++)
            for(int j1=0; j1<n; j1++)
                for(int i2=i1; i2<m; i2++)
                    for(int j2=j1; j2<n; j2++)
                        if(calculateSum(matrix, i1,j1,i2,j2) == target)
                            count++;
        return count;
    }
};