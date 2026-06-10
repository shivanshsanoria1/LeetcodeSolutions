class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m=grid.size(), n=grid[0].size();

        // index out of bounds
        if(i<0 || i>=m || j<0 || j>=n) 
            return 0;
        // no gold or visited element
        if(grid[i][j] <= 0) 
            return 0;

        // mark curr element as visited
        grid[i][j] *= -1; 

        int up = dfs(grid, i-1, j);
        int down = dfs(grid, i+1, j);
        int left = dfs(grid, i, j-1);
        int right = dfs(grid, i, j+1);

        // mark curr element as unvisited
        grid[i][j] *= -1; 

        return grid[i][j] + max(max(up, down), max(left, right));
    }

public:
    // T.C.=O(m*n*4^g)
    // g: num of cells with gold (+ive val)
    // multi-source-DFS + backtracking
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        int maxSum = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                maxSum += grid[i][j];

        int ans = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                ans = max(ans, dfs(grid, i, j));

                if(ans == maxSum)
                    return ans;
            }

        return ans;
    }
};