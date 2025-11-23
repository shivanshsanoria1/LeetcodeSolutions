class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(), n=mat[0].size();
        if(m*n != r*c) //reshaping matrix is not possible 
            return mat;
        vector<vector<int>> res(r,vector<int> (c));
        vector<int> temp;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                temp.push_back(mat[i][j]);
        int index=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                res[i][j]=temp[index];
                index++;
            }
        }
        return res;
    }
};