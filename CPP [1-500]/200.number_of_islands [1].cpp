class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y){
        int row=grid.size(), col=grid[0].size();
        if(x<0 || x>=row || y<0 || y>=col) // index out of bounds
            return;
        if(grid[x][y]=='0' || grid[x][y]=='2') // curr element is water or visited land
            return;
        grid[x][y] = '2'; // mark curr element, ie, unvisited land as visited
        dfs(grid, x-1, y); // up
        dfs(grid, x+1, y); // down
        dfs(grid, x, y-1); // left
        dfs(grid, x, y+1); // right
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(), col=grid[0].size();
        int islands = 0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid[i][j] == '1') // curr element is land
                {
                    dfs(grid, i, j);
                    islands++;
                }
        // [not required]: restore the original grid
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid[i][j] == '2')
                    grid[i][j] = '1';
        return islands;
    }
};
// 0: water, 1: unvisited land, 2: visited land