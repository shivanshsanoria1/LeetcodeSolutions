class Solution {
public:
    void dfs(vector<vector<bool>>& grid, vector<vector<bool>>& visited, int x, int y){
        int m=grid.size(), n=grid[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n) // index out of bounds
            return;
        if(!grid[x][y]) // no stone
            return;
        if(visited[x][y]) // already visited cell
            return;
        visited[x][y] = true;
        // run dfs() in for all cells in yth col
        for(int i=0; i<m; i++)
            dfs(grid, visited, i, y);
        // run dfs() in for all cells in xth row
        for(int j=0; j<n; j++)
            dfs(grid, visited, x, j);
    }

    int removeStones(vector<vector<int>>& stones) {
        int m=0, n=0;
        for(auto& stone: stones)
        {
            m = max(m, stone[0]);
            n = max(n, stone[1]);
        }
        vector<vector<bool>> grid(m+1, vector<bool>(n+1, false));
        for(auto& stone: stones) // mark the stones in the grid
            grid[stone[0]][stone[1]] = true;
        vector<vector<bool>> visited(m+1, vector<bool>(n+1, false));
        int count = 0;
        for(int i=0; i<=m; i++)
            for(int j=0; j<=n; j++)
                // run dfs() for only unvisited stones in the grid
                if(grid[i][j] && !visited[i][j])
                {
                    dfs(grid, visited, i, j);
                    count++;
                }
        return stones.size() - count;
    }
};
/*
# 'count' counts the number of times dfs() is run, ie, 
# number of groups of stones that are connected row or col wise
*/