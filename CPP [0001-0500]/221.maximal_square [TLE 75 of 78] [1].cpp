class Solution {
private:
    // returns true if the square submatrix with top-left corner at (x1, y1)
    // and bottom-right corner at (x2, y2) is filled with all 1's
    bool isSquareFilledWithAll_1s(vector<vector<char>>& matrix, int x1, int y1, int x2, int y2){
        for(int i=x1; i<=x2; i++)
            for(int j=y1; j<=y2; j++)
                if(matrix[i][j] == '0')
                    return false;
        return true;
    }

public:
    // T.C.=O((m*n)^2), S.C.=O(1)
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int maxArea = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                for(int k=0; i+k < m && j+k < n; k++)
                {
                    if(!isSquareFilledWithAll_1s(matrix, i, j, i+k, j+k))
                        break;
                    maxArea = max(maxArea, (k+1)*(k+1));
                }

        return maxArea;
    }
};