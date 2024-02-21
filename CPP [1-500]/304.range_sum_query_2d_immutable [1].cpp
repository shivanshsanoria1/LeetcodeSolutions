class NumMatrix {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> preSumRow; // prefix sum along row

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int m=matrix.size(), n=matrix[0].size();

        preSumRow.resize(m, vector<int>(n, 0)); // m*n matrix filled with 0's
        for(int i=0; i<m; i++) // fill the 0th col
            preSumRow[i][0] = matrix[i][0];
        for(int i=0; i<m; i++)
            for(int j=1; j<n; j++)
                preSumRow[i][j] = matrix[i][j] + preSumRow[i][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1; i<=row2; i++)
            sum += preSumRow[i][col2] - preSumRow[i][col1] + matrix[i][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */