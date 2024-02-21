class Solution {
public:
    // returns true if square matrix of size x size with upper-left corner at (a, b) is filled with all 1's
    bool isValidSquare(vector<vector<int>>& matrix, int a, int b, int size){
        int m=matrix.size(), n=matrix[0].size();
        if(a + size > m || b + size > n) // square not possible
            return false;
        for(int i=a; i < a + size; i++)
            for(int j=b; j < b + size; j++)
                if(matrix[i][j] == 0)
                    return false;
        return true;
    }

    int countSquares(vector<vector<int>>& matrix) { // T.C.=O(m*n*(min(m,n))^3), S.C.=O(1)
        int m=matrix.size(), n=matrix[0].size();
        int maxSqSize = min(m, n); // max dimension of square
        int count = 0;
        for(int k=1; k<=maxSqSize; k++)
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    if(isValidSquare(matrix, i, j, k))
                        count++;
        return count;
    }
};