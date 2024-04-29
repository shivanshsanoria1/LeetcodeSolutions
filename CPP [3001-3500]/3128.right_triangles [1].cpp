class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        vector<vector<int>> prefixSumRow(m, vector<int>(n, 0));
        vector<vector<int>> prefixSumCol(m, vector<int>(n, 0));

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(j == 0)
                    prefixSumRow[i][j] = grid[i][j];
                else
                    prefixSumRow[i][j] = prefixSumRow[i][j-1] + grid[i][j];
            }

        for(int j=0; j<n; j++)
            for(int i=0; i<m; i++)
            {
                if(i == 0)
                    prefixSumCol[i][j] = grid[i][j];
                else
                    prefixSumCol[i][j] = prefixSumCol[i-1][j] + grid[i][j];
            }

        long long int count = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                    continue;

                // number of 1's in up, down, left, right 
                // directions respectively
                int up = i-1 >= 0 ? prefixSumCol[i-1][j] : 0;
                int down = prefixSumCol[m-1][j] - prefixSumCol[i][j];
                int left = j-1 >= 0 ? prefixSumRow[i][j-1] : 0;
                int right = prefixSumRow[i][n-1] - prefixSumRow[i][j];

                count += up*left + up*right + down*left + down*right;
            }

        return count;
    }
};