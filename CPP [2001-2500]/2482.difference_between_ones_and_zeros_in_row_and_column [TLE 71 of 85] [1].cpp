class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) { // T.C.=O(m*n*(m+n)), S.C.=O(1)
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int row1s = 0;
                for(int k=0; k<n; k++)
                    row1s += grid[i][k];

                int col1s = 0;
                for(int k=0; k<m; k++)
                    row1s += grid[k][j];
                    
                ans[i][j] = row1s + col1s - (m - row1s) - (n - col1s);
            }
        return ans;
    }
};