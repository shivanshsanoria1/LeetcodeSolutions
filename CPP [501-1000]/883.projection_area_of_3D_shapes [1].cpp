class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int xy = 0, yz = 0, zx = 0;

        for(int i=0; i<n; i++) 
            for(int j=0; j<n; j++)
                if(grid[i][j] > 0)
                    xy++;

        for(int i=0; i<n; i++)
        {
            int maxVal = 0;
            for(int j=0; j<n; j++)
                maxVal = max(maxVal, grid[i][j]);
            yz += maxVal;
        }
        
        for(int j=0; j<n; j++)
        {
            int maxVal = 0;
            for(int i=0; i<n; i++)
                maxVal = max(maxVal, grid[i][j]);
            zx += maxVal;
        }

        return xy + yz + zx;
    }
};