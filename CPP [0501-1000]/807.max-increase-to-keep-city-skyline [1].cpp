class Solution {
public:
    // T.C.=O(m*n*(m+n)), S.C.=O(1)
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int sum = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int rowMax = 0;
                for(int k=0; k<n; k++)
                    rowMax = max(rowMax, grid[i][k]);
                int colMax = 0;
                for(int k=0; k<m; k++)
                    colMax = max(colMax, grid[k][j]);
                
                sum += min(rowMax, colMax) - grid[i][j];
            }

        return sum;
    }
};