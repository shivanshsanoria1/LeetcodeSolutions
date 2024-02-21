class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) { // T.C.=O(m*n), S.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        vector<int> temp(m*n);
        // map 2d array to an 1d array and shifted k times
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                temp[(n*i + j + k) % (m*n)] = grid[i][j];
        // map 1d array back to 2d array
        for(int i=0; i<m*n; i++)
            grid[i / n][i % n] = temp[i];
        return grid;
    }
};
/*
# both 2d and 1d array are of size m*n
# to convert 2d array to 1d array- arr1D[n*i + j] = arr2D[i][j]
# to convert 1d array to 2d array- arr2D[i / n][i % n] = arr1D[i]
*/