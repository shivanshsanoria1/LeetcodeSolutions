class NumMatrix {
private:
    // prefixSum[i][j]: sum of all elements in submatrix with 
    // top-left corner at (0, 0) and bottom-right corner at (i, j)
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->prefixSum = matrix;
        
        int m=matrix.size(), n=matrix[0].size();

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int pos1 = i-1 >= 0 ? prefixSum[i-1][j] : 0;
                int pos2 = j-1 >= 0 ? prefixSum[i][j-1] : 0;
                int neg1 = i-1 >= 0 && j-1 >= 0 ? prefixSum[i-1][j-1] : 0;

                this->prefixSum[i][j] += pos1 + pos2 - neg1;
            }
    }
    
    // T.C.=O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int pos1 = prefixSum[row2][col2];
        int neg1 = row1 - 1 >= 0 ? prefixSum[row1 - 1][col2] : 0;
        int neg2 = col1 - 1 >= 0 ? prefixSum[row2][col1 - 1] : 0;
        int pos2 = row1 - 1 >= 0 && col1 - 1 >= 0 ? prefixSum[row1 - 1][col1 - 1] : 0;

        return pos1 - neg1 - neg2 + pos2;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */