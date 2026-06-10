class Solution {
private:
    // returns max-val in the 9x9 grid centered at (x, y)
    int findMax(vector<vector<int>>& grid, int x, int y){
        int maxVal = 0;

        for(int i=x-1; i<=x+1; i++)
            for(int j=y-1; j<=y+1; j++)
                maxVal = max(maxVal, grid[i][j]);

        return maxVal;
    }

public:
    // T.C.=O(9*(n-2)^2), S.C.=O(1)
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));

        for(int i=1; i<n-1; i++)
            for(int j=1; j<n-1; j++)
                ans[i-1][j-1] = findMax(grid, i, j);

        return ans;
    }
};