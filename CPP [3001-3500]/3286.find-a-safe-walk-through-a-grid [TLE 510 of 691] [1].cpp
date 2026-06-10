class Solution {
private:
    bool solve(vector<vector<int>>& grid, int health, int i, int j, vector<vector<bool>>& visited){
        int m=grid.size(), n=grid[0].size();

        if(i<0 || i>=m || j<0 || j>=n)
            return false;

        if(visited[i][j])
            return false;

        if(grid[i][j] == 1)
            health--;
        
        if(health <= 0)
            return false;

        visited[i][j] = true;

        if(i == m-1 && j == n-1)
            return true;

        bool isFound = 
        solve(grid, health, i-1, j, visited) ||
        solve(grid, health, i+1, j, visited) ||
        solve(grid, health, i, j-1, visited) ||
        solve(grid, health, i, j+1, visited);

        visited[i][j] = false;
        
        return isFound;
    }

public:
    // Backtracking
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return solve(grid, health, 0, 0, visited);
    }
};