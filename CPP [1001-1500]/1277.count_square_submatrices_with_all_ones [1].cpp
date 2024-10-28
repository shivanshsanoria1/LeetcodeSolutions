class Solution {
private:
    // returns true if square matrix of k*k with 
    // upper-left corner at (a, b) is filled with all 1's
    bool isValidSquare(vector<vector<int>>& matrix, int a, int b, int k){
        for(int i=a; i < a + k; i++)
            for(int j=b; j < b + k; j++)
                if(matrix[i][j] == 0)
                    return false;

        return true;
    }

public:
    // T.C.=O(m*n*k^3), S.C.=O(1)
    // k = min(m, n)
    int countSquares(vector<vector<int>>& matrix) { 
        int m = matrix.size(), n = matrix[0].size();
        int count = 0;
        for(int k=1; k <= min(m, n); k++)
            for(int i=0; i+k<=m; i++)
                for(int j=0; j+k<=n; j++)
                    if(isValidSquare(matrix, i, j, k))
                        count++;

        return count;
    }
};