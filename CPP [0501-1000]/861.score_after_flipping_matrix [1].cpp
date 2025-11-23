class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    // modifying the input grid
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        // STEP 1: check if row needs to be flipped
        for(int i=0; i<m; i++)
        {
            if(grid[i][0] == 1)
                continue;

            // flip the row
            for(int j=0; j<n; j++)
                grid[i][j] = !grid[i][j];
        }

        // STEP 2: check if col needs to be flipped
        for(int j=0; j<n; j++)
        {
            int zeros = 0, ones = 0;

            for(int i=0; i<m; i++)
            {
                if(grid[i][j] == 0)
                    zeros++;
                else
                    ones++;
            }

            if(zeros <= ones)
                continue;
            
            // flip the col
            for(int i=0; i<m; i++)
                grid[i][j] = !grid[i][j];
        }

        // STEP 3: calculate the sum 
        int sum = 0;
        int mul = 1; // multiplier

        for(int j=n-1; j>=0; j--)
        {
            for(int i=0; i<m; i++)
                sum += grid[i][j] * mul;
            mul *= 2;
        }

        return sum;
    }
};
/*
# if a row starts with 0, then flip that row
# if a col has more 0's than 1's, then flip that col
*/