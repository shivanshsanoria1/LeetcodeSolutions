class Solution {
public:
    // T.C.=O(m*n), S.C.=O(1)
    // without modifying the input grid
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        int sum = 0;

        for(int i=0; i<m; i++)
        {
            int mul = 1;

            if(grid[i][0] == 0)
            {
                for(int j=n-1; j>=0; j--, mul *= 2)
                    sum += !grid[i][j] * mul;
            }
            else
            {
                for(int j=n-1; j>=0; j--, mul *= 2)
                    sum += grid[i][j] * mul;
            }
        }

        int mul = 1;

        for(int j=n-1; j>=0; j--, mul *= 2)
        {
            int zeros = 0, ones = 0;

            for(int i=0; i<m; i++)
            {
                // this row was flipped, 
                // so count of 0's and 1's are also flipped
                if(grid[i][0] == 0)
                {
                    if(grid[i][j] == 0)
                        ones++;
                    else
                        zeros++;
                }
                // this row was not flipped
                else
                {
                    if(grid[i][j] == 0)
                        zeros++;
                    else
                        ones++;
                }
            }
            
            if(zeros <= ones)
                continue;
            
            sum += (zeros - ones) * mul;
        }

        return sum;
    }
};
/*
# if a row starts with 0, then flip that row
# if a col has more 0's than 1's, then flip that col
*/