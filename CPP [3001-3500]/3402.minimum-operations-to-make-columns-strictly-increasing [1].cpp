class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ops = 0;

        for(int j=0; j<n; j++)
        {
            int prev = grid[0][j];
            for(int i=1; i<m; i++)
            {
                if(grid[i][j] <= prev)
                {
                    ops += prev - grid[i][j] + 1;
                    prev++;
                }
                else
                    prev = grid[i][j];
            }
        }

        return ops;
    }
};