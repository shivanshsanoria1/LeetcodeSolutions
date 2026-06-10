class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(n);
        for(int j=0; j<n; j++)
        {   
            int col=j;
            for(int i=0; i<m; i++)
            {
                if(grid[i][col] == 1 && col+1<n && grid[i][col+1] == 1)
                    ans[j]= ++col;
                else if(grid[i][col] == -1 && col-1>=0 && grid[i][col-1] == -1)
                    ans[j]= --col;
                else
                {
                    ans[j]=-1;
                    break;
                }
            }
        }
        return ans;
    }
};