class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int maxSum = 0;
        for(int i=1; i<m-1; i++)
            for(int j=1; j<n-1; j++)
            {
                int sum = grid[i][j];
                for(int k=-1; k<=1; k++)
                {
                    // prev row
                    sum += grid[i-1][j+k];
                    // next row
                    sum += grid[i+1][j+k];
                }
                maxSum = max(maxSum, sum);
            }
        return maxSum;
    }
};