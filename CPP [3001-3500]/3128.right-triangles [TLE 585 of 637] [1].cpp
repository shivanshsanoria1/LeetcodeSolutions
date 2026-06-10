class Solution {
public:
    // T.C.=O(m*n*(m+n)), S.C.=O(1)
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        long long int count = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                    continue;

                // number of 1's in up, down, left, right 
                // directions respectively
                int up = 0;
                int down = 0;
                int left = 0;
                int right = 0;

                for(int k=i-1; k>=0; k--)
                    if(grid[k][j] == 1)
                        up++;

                for(int k=i+1; k<m; k++)
                    if(grid[k][j] == 1)
                        down++;

                for(int k=j-1; k>=0; k--)
                    if(grid[i][k] == 1)
                        left++;

                for(int k=j+1; k<n; k++)
                    if(grid[i][k] == 1)
                        right++;
                
                count += up*left + up*right + down*left + down*right;
            }

        return count;
    }
};