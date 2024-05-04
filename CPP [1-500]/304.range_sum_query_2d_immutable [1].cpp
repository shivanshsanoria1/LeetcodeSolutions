class NumMatrix {
private:
    // prefix sum for every row
    vector<vector<int>> prefixSumRow; 

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->prefixSumRow = matrix;

        int m=matrix.size(), n=matrix[0].size();

        // calculate prefix-sum for every row
        // skip the 0th col
        for(int i=0; i<m; i++)
            for(int j=1; j<n; j++)
                this->prefixSumRow[i][j] += this->prefixSumRow[i][j-1];
    }
    
    // T.C.=O(m)
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for(int i=row1; i<=row2; i++)
        {
            if(col1 - 1 >= 0)
                sum += prefixSumRow[i][col2] - prefixSumRow[i][col1 - 1];
            else
                sum += prefixSumRow[i][col2];
        }
    
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */