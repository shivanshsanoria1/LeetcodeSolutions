class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        if(i>=m || j>=n) //index out of bounds
            return 0;
        if(i==m-1 && j==n-1) //reached the destination
        {
            grid[i][j]=1;
            return grid[i][j];
        }
        if(grid[i][j] != -1) //solution already exists
            return grid[i][j];
        int down = solve(grid,m,n,i+1,j); //down
        int right = solve(grid,m,n,i,j+1); //right
        grid[i][j] = down + right;
        return grid[i][j];
    }
    
    int uniquePaths(int m, int n) { //T.C.=O(m*n) , S.C.=O(m*n)
        vector<vector<int>> grid(m,vector<int>(n,-1)); //m*n grid filled with -1's
        return solve(grid,m,n,0,0);
    }
};