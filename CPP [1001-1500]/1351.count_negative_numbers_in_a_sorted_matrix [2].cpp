class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int count = 0;
        int col = n-1;
        for(int i=0; i<m; i++)
            for(int j=col; j>=0; j--)
            {
                if(grid[i][j] < 0)
                {
                    count += m-i; // jth col have -ives from ith row
                    col--;
                }
                else
                    break;
            }
        return count;
    }
};
// starting at the top-right corner