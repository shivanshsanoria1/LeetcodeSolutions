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
        for(int j=0; j<n/2; j++) // reflection of matrix
            for(int i=0; i<n; i++)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[i][n-1-j];
                matrix[i][n-1-j]=temp;
            }
    }
};