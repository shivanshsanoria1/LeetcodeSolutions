class Solution {
public:
    bool isSquare(vector<vector<char>>& matrix, int x1, int y1, int x2, int y2)
    {
        for(int i=x1; i<=x2; i++)
            for(int j=y1; j<=y2; j++)
                if(matrix[i][j] == '0')
                    return false;
        return true;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m= matrix.size(), n= matrix[0].size();
        int max_area=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int k=0;
                while(i+k<m && j+k<n && matrix[i+k][j+k] == '1')
                {
                    if(isSquare(matrix,i,j,i+k,j+k)==false)
                        break;
                    k++;
                    max_area = max(max_area,k*k);
                }
            }
        }
        return max_area;
    }
};