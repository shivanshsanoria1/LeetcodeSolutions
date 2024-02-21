class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(), temp;
        for(int i=0; i<n; i++) // transpose of matrix
            for(int j=i; j<n; j++)
            {
                if(i!=j)
                {
                    temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
        for(int i=0; i<n; i++) // reflection of matrix
            reverse(matrix[i].begin(), matrix[i].end());
    }
};