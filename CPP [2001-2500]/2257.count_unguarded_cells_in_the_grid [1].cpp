class Solution {
private:
    // mark the cells guarded by the guard at (i, j)
    void guarding(vector<vector<int>>& grid, int i, int j) {
        int m=grid.size(), n=grid[0].size();

        // up
        for(int k=i-1; k>=0; k--)
        {
            if(grid[k][j] >= 2)
                break;
            grid[k][j] = 1;
        }

        // down
        for(int k=i+1; k<m; k++)
        {
            if(grid[k][j] >= 2)
                break;
            grid[k][j] = 1;
        }

        // left
        for(int k=j-1; k>=0; k--)
        {
            if(grid[i][k] >= 2)
                break;
            grid[i][k] = 1;
        }

        // right
        for(int k=j+1; k<n; k++)
        {
            if(grid[i][k] >= 2)
                break;
            grid[i][k] = 1;
        }
    }

public:
    // T.C.=O(m*n*(m+n)), S.C.=O(m*n)
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(vector<int>& guard: guards)
            grid[guard[0]][guard[1]] = 2;
        
        for(vector<int>& wall: walls)
            grid[wall[0]][wall[1]] = 3;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 2)
                    guarding(grid, i, j);

        int unvisitedCount = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 0)
                    unvisitedCount++;

        return unvisitedCount;
    }
};
// 0: empty cell (unvisited), 1: empty cell (visited)
// 2: guard, 3: wall