class Solution {
private:
    void dfs(vector<vector<bool>>& grid, vector<vector<bool>>& visited, int x, int y){
        int m=grid.size(), n=grid[0].size();
        // index out of bounds
        if(x < 0 || x >= m || y < 0 || y >= n) 
            return;
        // no stone
        if(!grid[x][y]) 
            return;
        // already visited stone
        if(visited[x][y]) 
            return;
        // mark the curr stone as visited
        visited[x][y] = true;

        // run dfs() for all cells in yth col
        for(int i=0; i<m; i++)
            dfs(grid, visited, i, y);
        // run dfs() for all cells in xth row
        for(int j=0; j<n; j++)
            dfs(grid, visited, x, j);
    }

public:
    // T.C.=O(m*n*(m+n)), S.C.=O(m*n)
    // m: max val of stone[0], n: max val of stone[1]
    int removeStones(vector<vector<int>>& stones) {
        // find the size of grid
        int m = 0, n = 0;
        for(vector<int>& stone: stones)
        {
            m = max(m, stone[0]);
            n = max(n, stone[1]);
        }

        // mark the stones in the grid
        vector<vector<bool>> grid(m+1, vector<bool>(n+1, false));
        for(vector<int>& stone: stones) 
        {
            int x = stone[0];
            int y = stone[1];
            grid[x][y] = true;
        }

        vector<vector<bool>> visited(m+1, vector<bool>(n+1, false));
        int components = 0;
        for(int i=0; i<=m; i++)
            for(int j=0; j<=n; j++)
                if(grid[i][j] && !visited[i][j])
                {
                    dfs(grid, visited, i, j);
                    components++;
                }

        return stones.size() - components;
    }
};

// component means the stones that are connected row or col wise