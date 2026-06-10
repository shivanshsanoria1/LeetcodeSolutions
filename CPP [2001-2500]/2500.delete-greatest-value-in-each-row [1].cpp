class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) { // T.C.=O(m*n*logn), S.C.=O(1)
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++) // sort the grid row-wise
            sort(grid[i].begin(), grid[i].end());
        // find the max val in each col and add it to ans
        int ans = 0;
        for(int j=0; j<n; j++)
        {
            int maxVal = 0;
            for(int i=0; i<m; i++)
                maxVal = max(maxVal, grid[i][j]);
            ans += maxVal;
        }
        return ans;
    }
};