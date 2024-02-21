class Solution {
public:
    // retuns the length of the longest strictly increasing path starting at (i, j) 
    int dfs(vector<vector<int>>& matrix, int i, int j, int parVal){
        int m=matrix.size(), n=matrix[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n) // index out of bounds
            return 0;
        // parent value exists and curr val <= par val, ie, invalid path
        if(parVal != -1 && matrix[i][j] <= parVal)
            return 0;
        int up = dfs(matrix, i-1, j, matrix[i][j]);
        int down = dfs(matrix, i+1, j, matrix[i][j]);
        int left = dfs(matrix, i, j-1, matrix[i][j]);
        int right = dfs(matrix, i, j+1, matrix[i][j]);
        return 1 + max(max(up, down), max(left, right));
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) { // T.C.=O((m*n)^2), S.C.=O(1)
        int m=matrix.size(), n=matrix[0].size();
        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans = max(ans, dfs(matrix, i, j, -1));
        return ans;
    }
};