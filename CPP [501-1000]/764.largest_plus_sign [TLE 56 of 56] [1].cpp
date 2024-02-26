class Solution {
public:
    // T.C.=O(n^3), S.C.=O(n^2)
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // n*n grid filled with 1's
        vector<vector<int>> grid(n, vector<int>(n, 1));
        // mark the 0's in the grid
        for(int i=0; i<mines.size(); i++)
            grid[mines[i][0]][mines[i][1]] = 0;

        int k = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0)
                    continue;

                int up = 0, down = 0, left = 0, right = 0;

                // up
                for(int x=i-1; x>=0; x--)
                {
                    if(grid[x][j] == 1)
                        up++;
                    else
                        break;
                }
                // down
                for(int x=i+1; x<n; x++)
                {
                    if(grid[x][j] == 1)
                        down++;
                    else
                        break;
                }
                // left
                for(int y=j-1; y>=0; y--)
                {
                    if(grid[i][y] == 1)
                        left++;
                    else
                        break;
                }
                // right
                for(int y=j+1; y<n; y++)
                {
                    if(grid[i][y] == 1)
                        right++;
                    else
                        break;
                }

                k = max(k, 1 + min(min(up, down), min(left, right)));
            }

        return k;
    }
};