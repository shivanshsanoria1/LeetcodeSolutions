class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if(i<0 || i>=m || j<0 || j>=n) //index out of bounds
            return 0;
        if(grid[i][j]<=0) //no gold or visited element
            return 0;
        grid[i][j] *= -1; //mark curr element as visited
        int up= solve(grid,m,n,i-1,j);
        int down= solve(grid,m,n,i+1,j);
        int left= solve(grid,m,n,i,j-1);
        int right= solve(grid,m,n,i,j+1);
        grid[i][j] *= -1; //mark curr element as unvisited
        return grid[i][j] + max(up,max(down,max(left,right))); //return the sum of curr element and the max from all the 4 directions
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans= max(ans,solve(grid,m,n,i,j));
        return ans;
    }
};