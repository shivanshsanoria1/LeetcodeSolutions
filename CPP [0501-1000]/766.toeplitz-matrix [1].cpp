class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        for(int j=0; j<n; j++) //0th row
        {
            int r=0, c=j;
            while(r<m && c<n) //check the diagonals starting from matrix[0][j]
            {
                if(matrix[r][c]!=matrix[0][j]) //diagonal elements are not equal
                    return false;
                else //move to next diagonal element
                {
                    r++;
                    c++;
                }
            }
        }
        for(int i=0; i<m; i++) //0th col
        {
            int r=i, c=0;
            while(r<m && c<n) //check the diagonals starting from matrix[i][0]
            {
                if(matrix[r][c]!=matrix[i][0]) //diagonal elements are not equal
                    return false;
                else //move to next diagonal element
                {
                    r++;
                    c++;
                }
            }
        }
        return true;
    }
};