class Solution {
public:
    // T.C.=O(100^2), S.C.=O(100^2)
    double champagneTower(int poured, int query_row, int query_glass) {
        // 100*100 grid filled with 0's
        vector<vector<double>>grid(100, vector<double>(100, 0));

        grid[0][0] = (double)poured;

        for(int i=0; i<100; i++)
        {
            bool overflowFound = false;

            for(int j=0; j<=i; j++)
            {
                // no overflow from curr glass
                if(grid[i][j] <= 1)
                    continue;

                // overflow vol from curr glass
                double overflow = grid[i][j] - 1;
                // curr glass is now full
                grid[i][j] = 1;
                
                overflowFound = true;

                // next row is out of bounds
                if(i+1 >= 100)
                    break;

                // overflow vol from curr glass is equally
                // distributed among its 2 child glasses
                grid[i+1][j] += overflow / 2;
                grid[i+1][j+1] += overflow / 2;
            }

            // no need to check for the next row if 
            // no overflow is found in curr row
            if(!overflowFound)
                break;
        }

        return grid[query_row][query_glass]; 
    }
};
// grid[i][j]: input vol being poured into the (i, j)th glass