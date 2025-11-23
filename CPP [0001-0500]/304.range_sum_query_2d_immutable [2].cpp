class NumMatrix {
private:
    // prefix sum for every row
    vector<vector<int>> prefixSumRow; 
    // prefix sum for every col
    vector<vector<int>> prefixSumCol; 

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->prefixSumRow = matrix;
        this->prefixSumCol = matrix;

        int m=matrix.size(), n=matrix[0].size();

        // calculate prefix-sum for every row
        // skip the 0th col
        for(int i=0; i<m; i++)
            for(int j=1; j<n; j++)
                this->prefixSumRow[i][j] += this->prefixSumRow[i][j-1];

        // calculate prefix-sum for every col
        // skip the 0th row
        for(int j=0; j<n; j++)
            for(int i=1; i<m; i++)
                this->prefixSumCol[i][j] += this->prefixSumCol[i-1][j];
    }
    
    // T.C.=O(min(m, n))
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        if(row2 - row1 <= col2 - col1)
        {
            for(int i=row1; i<=row2; i++)
            {
                if(col1 - 1 >= 0)
                    sum += prefixSumRow[i][col2] - prefixSumRow[i][col1 - 1];
                else
                    sum += prefixSumRow[i][col2];
            }
        }
        else
        {
            for(int j=col1; j<=col2; j++)
            {
                if(row1 - 1 >= 0)
                    sum += prefixSumCol[row2][j] - prefixSumCol[row1 - 1][j];
                else
                    sum += prefixSumCol[row2][j];
            }
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */