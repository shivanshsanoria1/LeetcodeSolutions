class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    // DP-Tabulation with Space-Optimization
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<int> prevRow(n, 0);
        vector<int> currRow(n, 0);

        // 1st and 2nd max val in a row
        int min1 = INT_MAX, min2 = INT_MAX;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == 0)
                {
                    prevRow[j] = grid[i][j];
                    currRow[j] = grid[i][j];
                }
                else
                    currRow[j] = grid[i][j] + (prevRow[j] == min1 ? min2 : min1);
            }
            
            // reset min1 and min2
            min1 = INT_MAX, min2 = INT_MAX;

            for(int j=0; j<n; j++)
            {
                // update the prev-row with curr-row
                prevRow[j] = currRow[j];

                // update min1 and min2
                if(prevRow[j] <= min1)
                {
                    min2 = min1;
                    min1 = prevRow[j];
                }
                else if(prevRow[j] < min2)
                    min2 = prevRow[j];
            }
        }
        
        return min1;
    }
};