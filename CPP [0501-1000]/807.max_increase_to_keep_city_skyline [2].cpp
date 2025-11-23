class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m + n)
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        // find max element in each row
        vector<int> rowMaxes(m, 0);
        for(int i=0; i<m; i++)
        {
            int rowMax = 0;
            for(int j=0; j<n; j++)
                rowMax = max(rowMax, grid[i][j]);
            rowMaxes[i] = rowMax;
        }
        // find max element in each col
        vector<int> colMaxes(n, 0);
        for(int j=0; j<n; j++)
        {
            int colMax = 0;
            for(int i=0; i<m; i++)
                colMax = max(colMax, grid[i][j]);
            colMaxes[j] = colMax;
        }

        int sum = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                sum += min(rowMaxes[i], colMaxes[j]) - grid[i][j];
        return sum;
    }
};