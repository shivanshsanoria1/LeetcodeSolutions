class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) { //T.C.=O(m*n) , S.C.=O(m*n) , BFS
        int m=grid.size(), n=grid[0].size();
        queue<pair<int,int>> q; //to store the index of rotten oranges
        int fresh=0, time=-1;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2) //rotten orange
                    q.push({i,j});
                else if(grid[i][j]==1) //fresh orange
                    fresh++;
            }
        while(!q.empty())
        {
            int size= q.size();
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i-1>=0 && grid[i-1][j]==1) //up
                {
                    grid[i-1][j]=2;
                    fresh--;
                    q.push({i-1,j});
                }
                if(i+1<m && grid[i+1][j]==1) //down
                {
                    grid[i+1][j]=2;
                    fresh--;
                    q.push({i+1,j});
                }
                if(j-1>=0 && grid[i][j-1]==1) //left
                {
                    grid[i][j-1]=2;
                    fresh--;
                    q.push({i,j-1});
                }
                if(j+1<n && grid[i][j+1]==1) //right
                {
                    grid[i][j+1]=2;
                    fresh--;
                    q.push({i,j+1});
                }
            }
            time++;
        }
        if(fresh > 0) //fresh oranges are left
            return -1;
        if(time == -1) //no rotten oranges were present initially
            return 0;
        return time;
    }
};