class Solution {
private:
    // returns the sum of all elements in the subgrid with 
    // top-left corner at (0, 0) and bottom-right corner at (endX, endY)
    int getSubgridSum(vector<vector<int>>& grid, int endX, int endY) {
        int sum = 0;
        for(int i=0; i<=endX; i++)
            for(int j=0; j<=endY; j++)
                sum += grid[i][j];
        return sum;
    }

public:
    // T.C.=O((m*n)^2), S.C.=O(1)
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        int count = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int subgridSum = getSubgridSum(grid, i, j);
                if(subgridSum > k)
                    break;
                else
                    count++;
            }
        return count;
    }
};