class Solution {
public:
    void shiftGrid1Time(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> temp(m, vector<int>(n));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(j+1 < n)
                    temp[i][j+1] = grid[i][j];
                else if(i+1 < m)
                    temp[i+1][0] = grid[i][j];
                else
                    temp[0][0] = grid[i][j];
            }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                grid[i][j] = temp[i][j];
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) { // T.C.=O(m*n*k), S.C.=O(m*n)
        while(k--)
            shiftGrid1Time(grid);
        return grid;
    }
};