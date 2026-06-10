class Solution {
private:
    // returns the sum of all elements in the submatrix with 
    // top-left corner at (x-k, y-k) and bottom-right corner at (x+k, y+k)
    int getSum(vector<vector<int>>& mat, int k, int x, int y) {
        int m=mat.size(), n=mat[0].size();
        int sum = 0;
        for(int i = max(x-k, 0); i <= min(x+k, m-1); i++)
            for(int j = max(y-k, 0); j <= min(y+k, n-1); j++)
                sum += mat[i][j];
        return sum;
    }

public:
    // T.C.=O(m*n*k^2), S.C.=O(1)
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans[i][j] = getSum(mat, k, i, j);
        
        return ans;
    }
};