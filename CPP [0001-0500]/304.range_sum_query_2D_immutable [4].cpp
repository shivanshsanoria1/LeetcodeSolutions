class NumMatrix {
private:
    // prefixSum[i][j]: sum of all elements in submatrix with 
    // top-left corner at (0, 0) and bottom-right corner at (i-1, j-1)
    // 0th row and 0th col are for padding and filled with 0's
    // prefixSum[i][j] <---> matrix[i-1][j-1]
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();

        this->prefixSum.resize(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {
                int pos1 = this->prefixSum[i-1][j];
                int pos2 = this->prefixSum[i][j-1];
                int neg1 = this->prefixSum[i-1][j-1];

                this->prefixSum[i][j] = matrix[i-1][j-1] + pos1 + pos2 - neg1;
            }
    }
    
    // T.C.=O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int pos1 = prefixSum[row2 + 1][col2 + 1];
        int neg1 = prefixSum[row1][col2 + 1];
        int neg2 = prefixSum[row2 + 1][col1];
        int pos2 = prefixSum[row1][col1];

        return pos1 - neg1 - neg2 + pos2;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */