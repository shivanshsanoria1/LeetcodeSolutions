class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        for(int j=0; j<n; j++)
        {
            int maxVal = 0;
            for(int i=0; i<m; i++)
                maxVal = max(maxVal, matrix[i][j]);
            for(int i=0; i<m; i++)
                if(matrix[i][j] == -1)
                    matrix[i][j] = maxVal;
        }
        return matrix;
    }
};