class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) { // T.C.=O(m*n), S.C.=O(m+n)
        int m=grid.size(), n=grid[0].size();
        vector<int> row1s(m, 0), col1s(n, 0);
        // find the freq of 1's in each row
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                row1s[i] += grid[i][j];
        // find the freq of 1's in each col
        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
                col1s[j] += grid[i][j];

        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans[i][j] = row1s[i] + col1s[j] - (m - row1s[i]) - (n - col1s[j]);
        return ans;
    }
};