class Solution {
private:
    // returns true if the submatrix with top-left corner at (x1, y1)
    // and bottom-right corner at (x2, y2) is filled with all 1's
    bool submatrixHasAll_1s(vector<vector<char>>& matrix, int x1, int y1, int x2, int y2){
        for(int i=x1; i<=x2; i++)
            for(int j=y1; j<=y2; j++)
                if(matrix[i][j] == '0')
                    return false;
        return true;
    }

public:
    // T.C.=O((m*n)^3), S.C.=O(1)
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int maxArea = 0;

        for(int i1=0; i1<m; i1++)
            for(int j1=0; j1<n; j1++)
            {
                if(matrix[i1][j1] == '0')
                    continue;
                    
                for(int i2=i1; i2<m; i2++)
                    for(int j2=j1; j2<n; j2++)
                    {
                        if(matrix[i2][j2] == '0')
                            continue;

                        if(submatrixHasAll_1s(matrix, i1, j1, i2, j2))
                            maxArea = max(maxArea, (i2-i1+1)*(j2-j1+1));
                    }
            }
        
        return maxArea;
    }
};