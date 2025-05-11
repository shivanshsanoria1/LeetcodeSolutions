class Solution {
private:
    typedef long long int lli;

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    // 2D prefix-sum
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<lli>> prefixSum(m, vector<lli>(n, 0));

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                lli north = i-1 >= 0 ? prefixSum[i-1][j] : 0;
                lli west = j-1 >= 0 ? prefixSum[i][j-1] : 0;
                lli northWest = i-1 >=0 && j-1 >= 0 ? prefixSum[i-1][j-1] : 0;

                prefixSum[i][j] = grid[i][j] + north + west - northWest;
            }
        
        // divide into 2 horizontal parts with row indexes: 
        // [0, i-1] and [i, m-1]
        for(int i=1; i<m; i++)
            if(prefixSum[i-1][n-1] * 2 == prefixSum[m-1][n-1])
                return true;
        
        // divide into 2 vertical parts with col indexes:
        // [0, j-1] and [j, n-1]
        for(int j=1; j<n; j++)
            if(prefixSum[m-1][j-1] * 2 == prefixSum[m-1][n-1])
                return true;

        return false;
    }
};

// prefixSum[i][j]: sum of all elements in the grid with 
// top-left corner at (0, 0) and bottom-right corner at (i, j)