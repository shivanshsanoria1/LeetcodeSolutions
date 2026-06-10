class Solution {
public:
    // T.C.=O(m*n), S.C.=O(m*n)
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        // grid of size m*n filled with 0's
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        int count = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                int north = i-1 >= 0 ? prefixSum[i-1][j] : 0;
                int west = j-1 >= 0 ? prefixSum[i][j-1] : 0;
                int northWest = i-1 >= 0 && j-1 >= 0 ? prefixSum[i-1][j-1] : 0;

                prefixSum[i][j] = grid[i][j] + north + west - northWest;

                if(prefixSum[i][j] > k)
                    break;
                else
                    count++;
            }
            
        return count;
    }
};
// prefixSum[i][j]: sum of all elements in the subgrid with 
// top-left corner at (0, 0) and bottom-right corner at (i, j)