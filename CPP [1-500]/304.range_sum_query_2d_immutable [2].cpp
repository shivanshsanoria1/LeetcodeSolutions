class NumMatrix {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> preSumRow; // prefix sum along row
    vector<vector<int>> preSumCol; // prefix sum along col

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int m=matrix.size(), n=matrix[0].size();
        // calculate prefix sum along row if num of row >= num of cols
        if(m >= n)
        {
            preSumRow.resize(m, vector<int>(n, 0)); // m*n matrix filled with 0's
            for(int i=0; i<m; i++) // fill the 0th col
                preSumRow[i][0] = matrix[i][0];
            for(int i=0; i<m; i++)
                for(int j=1; j<n; j++)
                    preSumRow[i][j] = matrix[i][j] + preSumRow[i][j-1];
        }
        // calculate prefix sum along col if num of cols > num of rows
        else
        {
            preSumCol.resize(m, vector<int>(n, 0)); // m*n matrix filled with 0's
            for(int j=0; j<n; j++) // fill the 0th row
                preSumCol[0][j] = matrix[0][j];
            for(int j=0; j<n; j++)
                for(int i=1; i<m; i++)
                    preSumCol[i][j] = matrix[i][j] + preSumCol[i-1][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if(preSumRow.size() > 0)
            for(int i=row1; i<=row2; i++)
                sum += preSumRow[i][col2] - preSumRow[i][col1] + matrix[i][col1];
        else
            for(int j=col1; j<=col2; j++)
                sum += preSumCol[row2][j] - preSumCol[row1][j] + matrix[row1][j];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */