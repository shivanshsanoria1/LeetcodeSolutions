class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(), n=mat[0].size();
        if(m*n != r*c) //reshaping matrix is not possible 
            return mat;
        vector<vector<int>> res(r,vector<int> (c));
        int row=0, col=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                res[row][col]=mat[i][j];
                col++;
                if(col==c)
                {
                    row++;
                    col=0;
                }
            }
        }
        return res;
    }
};