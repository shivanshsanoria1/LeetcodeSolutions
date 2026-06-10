class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();
        // index out of bounds
        if(i<0 || i>=m || j<0 || j>=n) 
            return;
        // curr element not unvisited-land
        if(grid[i][j] != '1') 
            return;
        // mark the curr land as visited
        grid[i][j] = '2'; 

        dfs(grid, i-1, j); // up
        dfs(grid, i+1, j); // down
        dfs(grid, i, j-1); // left
        dfs(grid, i, j+1); // right
    }

    void restoreGrid(vector<vector<char>>& grid){
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == '2')
                    grid[i][j] = '1';
    }

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int islands = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    islands++;
                }

        restoreGrid(grid);

        return islands;
    }
};
// 0: water, 1: unvisited-land, 2: visited-land