class Solution {
public:
    // T.C.=C(m*n), S.C.=O(1)
    // Greedy
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size(), n=colSum.size();
        // grid of size m*n filled with 0's
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // fill the 0th row with col sums
        for(int j=0; j<n; j++)
            grid[0][j] = colSum[j];

        for(int i=0; i<m-1; i++)
        {
            long long int currRowSum = 0;
            for(int j=0; j<n; j++)
                currRowSum += grid[i][j];

            // diff between required and curr row sum
            long long int diff = currRowSum - rowSum[i];

            for(int j=0; j<n && diff > 0; j++)
            {
                // excess val present in the curr cell
                int excessVal = min((long long int)grid[i][j], diff);
                // send the excess val to the next row cell
                grid[i+1][j] = excessVal;
                // remove the excess val from curr cell and diff
                grid[i][j] -= excessVal;
                diff -= excessVal;
            }
        }

        return grid;
    }
};
// since a solution is guranteed to be found, 
// no need to check for the last row