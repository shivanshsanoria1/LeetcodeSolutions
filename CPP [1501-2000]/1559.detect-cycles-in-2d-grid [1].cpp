class Solution {
public:
    // (i,j): curr cell, (pi,pj): parent cell
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& dirs, int pi, int pj, int i, int j){
        int m=grid.size(), n=grid[0].size();
        visited[i][j] = true; // mark the curr cell as visited
        for(auto [dx, dy]: dirs)
        {
            int x = i + dx; // next cell x coordinate
            int y = j + dy; // next cell y coordinate
            if(x < 0 || x >= m || y < 0 || y >= n) // index out of bounds
                continue;
            if(grid[x][y] != grid[i][j]) // char mismatch between next and curr cell
                continue;
            if(x == pi && y == pj) // next cell is the parent cell of curr cell
                continue;
            if(visited[x][y]) // already visited cell which is not the parent cell, ie, loop found
                return true;
            if(dfs(grid, visited, dirs, i, j, x, y))
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) { // T.C.=O(m*n), S.C.=O(m*n)
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector(n, false));
        // directions- up, down, left, right
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                // run dfs() only for unvisited cells
                if(!visited[i][j] && dfs(grid, visited, dirs, -1, -1, i, j))
                    return true;
        return false;
    }
};