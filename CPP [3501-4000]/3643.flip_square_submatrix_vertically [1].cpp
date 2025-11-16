class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size(), n = grid[0].size();
        for(int j=y; j<y+k; j++)
            for(int left = x, right = x+k-1; left < right; left++, right--)
                swap(grid[left][j], grid[right][j]);

        return grid;
    }
};