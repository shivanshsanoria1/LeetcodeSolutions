class Solution {
private:
    bool isBorderCell(vector<vector<int>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();

        bool up = i-1 >= 0 ? abs(grid[i-1][j]) == abs(grid[i][j]) : false;
        bool down = i+1 < m ? abs(grid[i+1][j]) == abs(grid[i][j]) : false;
        bool left = j-1 >= 0 ? abs(grid[i][j-1]) == abs(grid[i][j]) : false;
        bool right = j+1 < n ? abs(grid[i][j+1]) == abs(grid[i][j]) : false;

        return up && down && left && right ? false : true;
    }

    void dfs2(vector<vector<int>>& grid, vector<vector<bool>>& isBorder, int i, int j){
        int m=grid.size(), n=grid[0].size();

        // index out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
        // unvisited cell
        if(grid[i][j] > 0)
            return;

        // mark the curr cell as unvisited
        grid[i][j] *= -1;
        
        // curr cell is the border-cell of the component
        if(isBorderCell(grid, i, j))
            isBorder[i][j] = true;

        dfs2(grid, isBorder, i-1, j); // up
        dfs2(grid, isBorder, i+1, j); // down
        dfs2(grid, isBorder, i, j-1); // left
        dfs2(grid, isBorder, i, j+1); // right
    }

    void dfs1(vector<vector<int>>& grid, int startColor, int i, int j){
        int m=grid.size(), n=grid[0].size();

        // index out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
        // already visited cell
        if(grid[i][j] < 0)
            return;
        // curr cell does not belong to the same component
        if(grid[i][j] != startColor)
            return;

        // mark the curr cell as visited
        grid[i][j] *= -1;

        dfs1(grid, startColor, i-1, j); // up
        dfs1(grid, startColor, i+1, j); // down
        dfs1(grid, startColor, i, j-1); // left
        dfs1(grid, startColor, i, j+1); // right

    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m=grid.size(), n=grid[0].size();
        int startColor = grid[row][col];

        // find the component starting at (row, col)
        dfs1(grid, startColor, row, col);

        // find the border-cells of the component
        vector<vector<bool>> isBorder(m, vector<bool>(n, false));
        dfs2(grid, isBorder, row, col);

        // change the color of border-cells
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(isBorder[i][j])
                    grid[i][j] = color;

        return grid;
    }
};