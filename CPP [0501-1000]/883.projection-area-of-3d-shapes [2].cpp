class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int maxRow = 0;
            int maxCol = 0;
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] > 0)
                    ans++;
                maxRow = max(maxRow, grid[i][j]);
                maxCol = max(maxCol, grid[j][i]);
            }
            ans += maxRow + maxCol;
        }
        return ans;
    }
};