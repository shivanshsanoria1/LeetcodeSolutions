class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> temp_grid(m,vector<int>(n));
        int fresh_left=0, c=0;
        while(1)
        {
            int fresh=0, temp_fresh=0;
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                {
                    if(grid[i][j]==1)
                        fresh++;
                    temp_grid[i][j]=grid[i][j];
                }
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    if(grid[i][j]==2) //rotten orange
                    {
                        if(i-1>=0 && grid[i-1][j]==1) //up
                            temp_grid[i-1][j]=2;
                        if(i+1<m && grid[i+1][j]==1) //down
                            temp_grid[i+1][j]=2;
                        if(j-1>=0 && grid[i][j-1]==1) //left
                            temp_grid[i][j-1]=2;
                        if(j+1<n && grid[i][j+1]==1) //right
                            temp_grid[i][j+1]=2;
                    }
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                {
                    if(temp_grid[i][j]==1)
                        temp_fresh++;
                    grid[i][j]=temp_grid[i][j];
                }
            if(fresh==temp_fresh)
            {
                fresh_left=fresh;
                break;
            }
            c++;
        }
        return fresh_left==0 ? c : -1;
    }
};